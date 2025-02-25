#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>

class BTreeNode {
public:
    bool leaf;
    std::vector<std::string> keys;
    std::vector<BTreeNode*> children;
    int minDegree;  // Minimum degree (t) for the B-Tree

    BTreeNode(int minDegree, bool leaf);
    void insertNonFull(std::string key);
    void splitChild(int i, BTreeNode* y);
    void traverse();
    BTreeNode* search(std::string key);
    int findKey(std::string key);
    void remove(std::string key);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    std::string getPredecessor(int idx);
    std::string getSuccessor(int idx);
    void merge(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void fill(int idx);

    friend class BTree;
};

class BTree {
public:
    BTreeNode* root;
    int minDegree;

    BTree(int minDegree);
    void traverse();
    BTreeNode* search(std::string key);
    void insert(std::string key);
    void remove(std::string key);
};

#endif // BTREE_H
