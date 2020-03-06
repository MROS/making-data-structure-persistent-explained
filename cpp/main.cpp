#include "order_tree.hpp"
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    OrderTree *order_tree = new OrderTree(3);
    order_tree->show();
    vector<Node*> nodes;
    for (int i = 0; i < 4; i++) {
        auto ret = order_tree->add(i);
        order_tree = ret.first;
        nodes.push_back(ret.second);
        order_tree->show();
    }
    // auto ret = order_tree->change_value(nodes[0], 100);
    // ret.first->show();
    auto ret = order_tree->to_head(nodes[0]);
    order_tree = ret.first;
    order_tree->show();

    ret = order_tree->to_head(nodes[1]);
    order_tree = ret.first;
    order_tree->show();

    ret = order_tree->to_head(nodes[2]);
    order_tree = ret.first;
    order_tree->show();

    ret = order_tree->to_head(nodes[3]);
    order_tree = ret.first;
    order_tree->show();
}