#include "BTree.h"
#include <thread>
#include <mutex>

std::mutex db_mutex;

void queryDatabase(BTree& db, std::string key) {
    std::lock_guard<std::mutex> lock(db_mutex);
    std::cout << "Query: " << key << " -> " 
              << (db.search(key) ? "Found" : "Not Found") << std::endl;
}

int main() {
    BTree db(3);
    db.insert("transistor M1");
    db.insert("resistor R1");

    std::thread t1(queryDatabase, std::ref(db), "transistor M1");
    std::thread t2(queryDatabase, std::ref(db), "capacitor C1");

    t1.join();
    t2.join();

    return 0;
}
