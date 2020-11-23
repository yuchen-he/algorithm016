/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    stack<int> my_stack;     // 易错点：类变量定义在类下面，而非构造函数里面（构造函数里面赋值可以）
    int min_value;

    MinStack() {
        min_value = INT_MAX;    
    }
    
    void push(int x) {
        if (x <= min_value) {
            my_stack.push(min_value);
            min_value = x;
        }
        my_stack.push(x);       // push(x)这一步不论什么值进来都要进行，所以不必if-else分开
    }
    
    void pop() {
        if (my_stack.top() == min_value) {               // C++中stack.pop()不返回值
            my_stack.pop();
            min_value = my_stack.top();
            my_stack.pop();
        }
        else {my_stack.pop();}
    }
    
    int top() {
        return my_stack.top();
    }
    
    int getMin() {
        return min_value;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

