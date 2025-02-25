#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    int fd = open("ic_data.bin", O_RDWR | O_CREAT, 0666);
    size_t FILE_SIZE = 1024;
    ftruncate(fd, FILE_SIZE);

    void* map = mmap(NULL, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        std::cerr << "mmap failed" << std::endl;
        return 1;
    }

    char* data = static_cast<char*>(map);
    sprintf(data, "transistor M1 width=1.2u length=0.18u");
    
    std::cout << "Stored: " << data << std::endl;
    munmap(map, FILE_SIZE);
    close(fd);
    return 0;
}
