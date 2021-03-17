/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
class DNode {
public:
    DNode(int k, int v, DNode* p = NULL, DNode* n = NULL) {
        key = k;
        value = v;
        prev = p;
        next = n;
    }
    int key;
    int value;
    DNode *prev;
    DNode *next;
};

class LRUCache {
private:
    int cap;
    map<int, DNode*> hashMap;
    DNode* dummyHead;
    DNode* dummyTail;

public:
    LRUCache(int capacity) {
        // 初始化容量和哈希表
        cap = capacity;

        // 初始化头尾的空节点
        dummyHead = new DNode(0, 0);
        dummyTail = new DNode(0, 0);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    
    int get(int key) {
        // 从hashMap中查找该key
        if (hashMap.count(key) > 0) {
            // 如果存在，则返回value。并且调用put把它移到first位置（因为最近使用了）
            int val = hashMap[key]->value;
            put(key, val);
            return val;
        }
        else {
            // 否则返回-1
            return -1;
        }
    }
    
    void put(int key, int value) {
        // 要放入链表中，先生成一个node
        DNode* new_node = new DNode(key, value);

        // 判断key是否在hashMap中
        if (hashMap.count(key) > 0 ) {
            // 如果存在，则先从链表和hashMap中删除该旧节点（因为无论如果之后都还要把它addFirst）
            deleteNode(hashMap[key]);
            hashMap.erase(hashMap.find(key));    // find(key)会返回迭代器，而erase传入迭代器的时候无返回值（也可以int dummy = hashMap.erase(key)）
            cap++;
        }
        else {
            // 如果不存在，先判断缓存容量
            if (cap <= 0) {
                // 如果容量满了，从链表中删除最后一个节点，并且从hashMap中也删除（因此deleteTail要返回最后那个节点的key）
                int oldKey = deleteTail();
                hashMap.erase(hashMap.find(oldKey));
                cap++;
            }
        }

        // 然后addFirst，把新节点加入到链表和hashMap中
        addFirst(new_node);
        hashMap[key] = new_node;
        cap--;
    }

    int deleteTail() {
        DNode* oldTail = dummyTail->prev;
        DNode* newTail = oldTail->prev;
        newTail->next = dummyTail;
        dummyTail->prev = newTail;
        return oldTail->key;
    }

    void deleteNode(DNode* oldNode) {
        DNode* prev = oldNode->prev;
        DNode* next = oldNode->next;
        prev->next = next;
        next->prev = prev;
    }

    void addFirst(DNode* new_node) {
        DNode* oldFirst = dummyHead->next;
        dummyHead->next = new_node;
        oldFirst->prev = new_node;
        new_node->prev = dummyHead;
        new_node->next = oldFirst;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

