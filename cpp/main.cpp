#include "order_tree.hpp"
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    OrderTree *order_tree = new OrderTree(3);
    order_tree->show();
    for (int i = 0; i < 8; i++) {
        auto ret = order_tree->add(i);
        order_tree = ret.first;
        order_tree->show();
    }
}