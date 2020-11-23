/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    int* m_dequeue;
    int capacity;
    int front;                // 关键点: 用前后指针来指向队列的首尾（因为是循环的，所有f可能>r）
    int rear;

    MyCircularDeque(int k) {
        capacity = k+1;          // 为了使得判断empty和full条件不重叠，给数组多加一个空位（不固定的）
        m_dequeue = new int[capacity];
        front = 0;
        rear = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (!isFull()) {
            front = (front - 1 + capacity) % capacity;       // treak，防止index越界
            m_dequeue[front] = value;
            return true;
        }
        else {return false;}
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (!isFull()) {
            m_dequeue[rear] = value;
            rear = (rear + 1) % capacity;
            return true;
        }
        else {return false;}
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (!isEmpty()) {
            // m_dequeue[front] = -1;
            front = (front + 1) % capacity;
            return true;
        }
        else {return false;}
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (!isEmpty()) {
            rear = (rear - 1 + capacity) % capacity;
            // m_dequeue[rear] = -1;
            return true;
        }
        else {return false;}
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return m_dequeue[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return m_dequeue[(rear - 1 + capacity) % capacity];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (front == rear);
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return ((front - 1 + capacity) % capacity == rear);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

