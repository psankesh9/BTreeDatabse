#include "BTree.h"

int main() {
    BTree tree(3);

    tree.insert("transistor M1");
    tree.insert("resistor R1");
    tree.insert("capacitor C1");
    tree.insert("inductor L1");
    tree.insert("diode D1");

    std::cout << "B-Tree Traversal: ";
    tree.traverse();
    std::cout << "\n";

    std::cout << "Searching for transistor M1: " 
              << (tree.search("transistor M1") ? "Found" : "Not Found") << std::endl;

    return 0;
}
