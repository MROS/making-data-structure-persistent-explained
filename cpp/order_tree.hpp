#pragma once
#include <vector>

// NOTE: 有 enum 的話，可分成內部節點跟葉子節點
// TODO: 把 left, right 用 children[2] 取代
class Node {
public:
    Node *left, *right;
    int key;
    int value;          // value 若爲 -1 ，表示沒有 value
    int index;          // index 若爲 -1 ，表示其爲內部節點（而非葉子節點）
    Node() : left(nullptr), right(nullptr), key(0), value(-1), index(-1) {}
    Node(int index) : left(nullptr), right(nullptr), key(0), value(-1), index(index) {}
    Node(int index, int value) : left(nullptr), right(nullptr), key(0), value(value), index(index) {}
};

class OrderTree {
private:
    OrderTree *new_tree() {
        OrderTree *tree = new OrderTree();
        tree->height = this->height;
        tree->root = nullptr;
        tree->cursor = this->cursor;
        return tree;
    }
public:
    // 元素數量爲 2^(height-1) ，只佔用一半的葉子節點
    int height;
    Node *root;
    // cursor 代表當前最新葉子節點的索引，由左至右
    // 最左的葉子索引爲 0 ，最右的葉子索引爲 2^height - 1
    int cursor;
    OrderTree() = default;
    OrderTree(int height);
    OrderTree(int height, std::vector<int> &values);

    // 打印所有葉子節點
    void show();

    // 創建一個新的樹，新增一個節點到當前 cursor 位置，其值爲 value
    std::pair<OrderTree*, Node*> add(int value);

    // 創建一個新的樹， node 的值被修改爲 value
    std::pair<OrderTree*, Node*> change_value(Node *node, int value);

    // 創建一個新的樹， node 將被移到當前 cursor 位置
    std::pair<OrderTree*, Node*> to_head(Node *node);

    // 創建一個新的樹， node 的值被修改爲 value ，並且 node 將被移到當前 cursor 位置
    std::pair<OrderTree*, Node*> put(Node *node, int value);
    


    OrderTree* update(Node *node, int value);
};