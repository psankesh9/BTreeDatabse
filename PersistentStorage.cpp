#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>

#define FILE_SIZE 4096

class PersistentStorage {
public:
    int fd;
    char* map;

    PersistentStorage(const char* filename) {
        fd = open(filename, O_RDWR | O_CREAT, 0666);
        ftruncate(fd, FILE_SIZE);
        map = (char*)mmap(NULL, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        if (map == MAP_FAILED) {
            std::cerr << "mmap failed" << std::endl;
            exit(1);
        }
    }

    void store(const std::string& key, const std::string& value) {
        std::string entry = key + "=" + value + "\n";
        strcat(map, entry.c_str());
    }

    void load() {
        std::cout << "Data from file:\n" << map << std::endl;
    }

    ~PersistentStorage() {
        munmap(map, FILE_SIZE);
        close(fd);
    }
};

int main() {
    PersistentStorage storage("btree_data.bin");
    storage.store("transistor M1", "width=1.2u length=0.18u");
    storage.load();
    return 0;
}
