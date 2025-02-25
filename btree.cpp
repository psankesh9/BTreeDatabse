#include <iostream>
#include <map>
#include "BTreeNode.h"  // Include the header file

/*
class btree {
public:
    std::map<std::string, std::string> storage;

    void insert(std::string key, std::string value) {
        storage[key] = value;
    }

    std::string query(std::string key) {
        return storage.count(key) ? storage[key] : "Not Found";
    }
};
*/
class btree {
    private:
        BTreeNode* root;
    
        BTreeNode* search(BTreeNode* node, std::string key) {
            int i = 0;
            while (i < node->keys.size() && key > node->keys[i])
                i++;
            if (i < node->keys.size() && node->keys[i] == key)
                return node;
            if (node->leaf)
                return nullptr;
            return search(node->children[i], key);
        }
    
    public:
        btree() { root = new BTreeNode(true); }
    
        bool search(std::string key) {
            return search(root, key) != nullptr;
        }
    
        void insert(std::string key) {
            root->keys.push_back(key);  // Simple insertion (Extend for full B-Tree insert logic)
            std::sort(root->keys.begin(), root->keys.end());  // Keep sorted for binary search
        }
    };
    
int main() {
    btree db;
    db.insert("transistor M1", "width=1.2u length=0.18u");
    std::cout << "Query: " << db.query("transistor M1") << std::endl;
    return 0;
}
