#include "order_tree.hpp"
#include <stdio.h>
#include <vector>
using namespace std;

Node *_createFullTree(int height, int index, vector<int> &values) {
    if (height < 0) {
        throw "樹高度不得爲負";
    } else if (height == 0) {
        int value = values.size() > index ? values[index] : -1;
        return new Node(index, value);
    } else {
        auto root = new Node();
        root->left = _createFullTree(height - 1, index * 2, values);
        root->right = _createFullTree(height - 1, index * 2 + 1, values);
        return root;
    }
}

Node *createFullTree(int height, vector<int> &values) {
    return _createFullTree(height, 0, values);
}

OrderTree::OrderTree(int height) {
    this->height = height;
    this->cursor = 0;
    this->root = new Node();
}

OrderTree::OrderTree(int height, vector<int> &values) {
    this->height = height;
    this->cursor = values.size();
    this->root = createFullTree(height, values);
}

void _show(Node *node, int height) {
    if (node == nullptr) {
        for (int i = 0; i < (1 << height); i++) {
            printf("(空, 空) ");
        }
    } else if (height > 0) {
        // 爲內部節點
        _show(node->left, height - 1);
        _show(node->right, height - 1);
    } else {
        // 爲葉子節點
        printf("(%d, %d) ", node->key, node->value);
    }
}

void OrderTree::show() {
    _show(this->root, this->height);
    printf("\n");
}

std::pair<OrderTree*, Node*> OrderTree::add(int value) {
    Node *old_pointer = this->root;     // 原樹的指標
    Node *new_pointer = new Node();     // 正在創建的新樹的指標
    Node *new_root = new_pointer;
    for (int h = this->height - 1; h >= 0; h--) {
        if ((this->cursor & (1 << h)) == 0) {
            // 往左
            if (old_pointer != nullptr) {
                new_pointer->right = old_pointer->right;
                old_pointer = old_pointer->left;
            }
            new_pointer->left = new Node();
            new_pointer = new_pointer->left;
        } else {
            // 往右
            if (old_pointer != nullptr) {
                new_pointer->left = old_pointer->left;
                old_pointer = old_pointer->right;
            }
            new_pointer->right = new Node();
            new_pointer = new_pointer->right;
        }
    }
    new_pointer->index = this->cursor;
    new_pointer->value = value;
    OrderTree *new_tree = this->new_tree();
    new_tree->root = new_root;
    new_tree->cursor++;
    std::pair<OrderTree*, Node*> ret = {new_tree, new_pointer};
    return ret;
}

std::pair<OrderTree*, Node*> OrderTree::change_value(Node *node, int value) {
    Node *old_pointer = this->root;     // 原樹的指標
    Node *new_pointer = new Node();     // 正在創建的新樹的指標
    Node *new_root = new_pointer;
    for (int h = this->height - 1; h >= 0; h--) {
        if ((node->index & (1 << h)) == 0) {
            // 往左
            new_pointer->right = old_pointer->right;
            old_pointer = old_pointer->left;
            new_pointer->left = new Node();
            new_pointer = new_pointer->left;
        } else {
            // 往右
            new_pointer->left = old_pointer->left;
            old_pointer = old_pointer->right;
            new_pointer->right = new Node();
            new_pointer = new_pointer->right;
        }
    }
    new_pointer->value = value;
    OrderTree *new_tree = this->new_tree();
    new_tree->root = new_root;
    std::pair<OrderTree*, Node*> ret = {new_tree, new_pointer};
    return ret;
}

std::pair<OrderTree*, Node*> OrderTree::to_head(Node *node) {
    OrderTree *new_tree = new OrderTree();
    new_tree->height = this->height;

    new_tree->cursor = this->cursor + 1;
    std::pair<OrderTree*, Node*> ret = {nullptr, nullptr};
    return ret;
}

OrderTree *OrderTree::update(Node *node, int value) {
    return nullptr;
}