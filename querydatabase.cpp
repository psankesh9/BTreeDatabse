#include <iostream>
#include <thread>
#include <mutex>
#include <map>

std::map<std::string, std::string> storage;
std::mutex db_mutex;

void queryDatabase(std::string key) {
    std::lock_guard<std::mutex> lock(db_mutex);
    if (storage.count(key))
        std::cout << "Query: " << storage[key] << std::endl;
    else
        std::cout << "Not Found" << std::endl;
}

int main() {
    storage["transistor M1"] = "width=1.2u length=0.18u";

    std::thread t1(queryDatabase, "transistor M1");
    std::thread t2(queryDatabase, "transistor M2");

    t1.join();
    t2.join();
    return 0;
}
