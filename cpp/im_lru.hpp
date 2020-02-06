#include "order_tree.hpp"
#include <immer/map.hpp>

class ImmutableLRUCache {
private:
    int capacity;
    int used;
    OrderTree *order_tree;
    immer::map<int, Node*> map;
public:
    ImmutableLRUCache(int capacity);
    int get(int key);
    ImmutableLRUCache* put(int key, int value);
};