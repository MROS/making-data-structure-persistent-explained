#include "order_tree.hpp"
#include <immer/map.hpp>

class PersistentLRUCache {
private:
    int capacity;
    int used;
    OrderTree *order_tree;
    immer::map<int, Node*> map;
public:
    PersistentLRUCache(int capacity);
    int get(int key);
    PersistentLRUCache* put(int key, int value);
};