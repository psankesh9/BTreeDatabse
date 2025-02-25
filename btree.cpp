#include "BTree.h"
#include <algorithm>

BTreeNode::BTreeNode(int minDegree, bool leaf) : minDegree(minDegree), leaf(leaf) {}

void BTreeNode::traverse() {
    for (int i = 0; i < keys.size(); i++) {
        if (!leaf)
            children[i]->traverse();
        std::cout << keys[i] << " ";
    }
    if (!leaf)
        children[keys.size()]->traverse();
}

BTreeNode* BTreeNode::search(std::string key) {
    int i = 0;
    while (i < keys.size() && key > keys[i])
        i++;
    if (i < keys.size() && keys[i] == key)
        return this;
    if (leaf)
        return nullptr;
    return children[i]->search(key);
}

void BTreeNode::insertNonFull(std::string key) {
    int i = keys.size() - 1;
    if (leaf) {
        keys.push_back("");
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
    } else {
        while (i >= 0 && keys[i] > key)
            i--;
        if (children[i + 1]->keys.size() == 2 * minDegree - 1) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1] < key)
                i++;
        }
        children[i + 1]->insertNonFull(key);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->minDegree, y->leaf);
    for (int j = 0; j < minDegree - 1; j++)
        z->keys.push_back(y->keys[j + minDegree]);
    if (!y->leaf) {
        for (int j = 0; j < minDegree; j++)
            z->children.push_back(y->children[j + minDegree]);
    }
    y->keys.resize(minDegree - 1);
    children.insert(children.begin() + i + 1, z);
    keys.insert(keys.begin() + i, y->keys[minDegree - 1]);
}

BTree::BTree(int minDegree) : minDegree(minDegree) {
    root = new BTreeNode(minDegree, true);
}

void BTree::insert(std::string key) {
    if (root->keys.size() == 2 * minDegree - 1) {
        BTreeNode* s = new BTreeNode(minDegree, false);
        s->children.push_back(root);
        s->splitChild(0, root);
        int i = (s->keys[0] < key) ? 1 : 0;
        s->children[i]->insertNonFull(key);
        root = s;
    } else {
        root->insertNonFull(key);
    }
}

void BTree::traverse() {
    if (root)
        root->traverse();
}

BTreeNode* BTree::search(std::string key) {
    return root ? root->search(key) : nullptr;
}
