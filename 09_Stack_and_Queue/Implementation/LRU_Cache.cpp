#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
private:
    int cap;
    std::unordered_map<int, Node*> cache;
    Node* oldest;
    Node* latest;

public:
    LRUCache(int capacity) : cap(capacity) {
        oldest = new Node(0, 0);
        latest = new Node(0, 0);
        oldest->next = latest;
        latest->prev = oldest;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

private:
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = latest->prev;
        Node* next = latest;
        prev->next = next->prev = node;
        node->next = next;
        node->prev = prev;
    }

public:
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap) {
            Node* lru = oldest->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }

    // Destructor to release memory used by the nodes
    ~LRUCache() {
        Node* curr = oldest;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

/*
🧩 Core Idea (Game Plan)
Doubly Linked List → maintains the usage order of items (oldest → newest).
Unordered Map → allows O(1) access to any node by key.
When a key is accessed or updated, it’s moved to the "latest" (most recently used) end.
When capacity is exceeded, we remove the "oldest" (least recently used) one.

🧱 Structure
Node represents a (key, value) pair with prev and next pointers.
LRUCache maintains:
    unordered_map<int, Node*> cache → for fast lookups.
    Node* oldest and Node* latest → dummy nodes marking list boundaries.
    cap → max capacity.

⚙️ Key Functions
1️⃣ get(int key)
If found:
    Remove it from the current position.
    Insert it at the end (most recent position).
    Return its value.
Else → return -1.

2️⃣ put(int key, int value)
If key exists → remove the old node.
Insert a new node at the end (latest position).
If over capacity → remove from the front (the "oldest" node).

3️⃣ remove(Node* node)
Efficiently unlinks the node from the list.

4️⃣ insert(Node* node)
Inserts node before latest, making it the most recent.
*/