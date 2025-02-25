#include <iostream>
#include <vector>
#include "BTreeNode.h"
class BTreeNode {
public:
    bool leaf;
    std::vector<std::string> keys;
    std::vector<BTreeNode*> children;

    BTreeNode(bool leaf) : leaf(leaf) {}
};
