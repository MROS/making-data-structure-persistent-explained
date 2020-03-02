#include "order_tree.hpp"
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    OrderTree *order_tree = new OrderTree(3);
    order_tree->show();
    vector<Node*> nodes;
    for (int i = 0; i < 8; i++) {
        auto ret = order_tree->add(i);
        order_tree = ret.first;
        nodes.push_back(ret.second);
        order_tree->show();
    }
    auto ret = order_tree->change_value(nodes[0], -1);
    ret.first->show();
    ret = order_tree->change_value(nodes[1], -1);
    ret.first->show();
    ret = order_tree->change_value(nodes[2], -1);
    ret.first->show();
}