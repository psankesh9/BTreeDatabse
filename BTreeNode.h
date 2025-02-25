#ifndef BTREE_NODE_H
#define BTREE_NODE_H

#include <iostream>
#include <vector>

class BTreeNode {
public:
    bool leaf;
    std::vector<std::string> keys;
    std::vector<BTreeNode*> children;

    BTreeNode(bool leaf);
};

#endif // BTREE_NODE_H
