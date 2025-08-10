#include <iostream>
#include <unordered_map>
#include <memory>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {
        head = make_shared<Node>(-1, -1);
        tail = make_shared<Node>(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        auto node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            auto node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            if (cache.size() == capacity) {
                auto tailNode = tail->prev;
                cache.erase(tailNode->key);
                removeNode(tailNode);
            }
            auto newNode = make_shared<Node>(key, value);
            cache[key] = newNode;
            addToHead(newNode);
        }
    }

private:
    struct Node {
        int key, value;
        shared_ptr<Node> prev, next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, shared_ptr<Node>> cache;
    shared_ptr<Node> head, tail;

    void addToHead(shared_ptr<Node> node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(shared_ptr<Node> node) {
        auto prevNode = node->prev;
        auto nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void moveToHead(shared_ptr<Node> node) {
        removeNode(node);
        addToHead(node);
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */