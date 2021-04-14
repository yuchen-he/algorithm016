# 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）： 
# 
#  实现 MyQueue 类： 
# 
#  
#  void push(int x) 将元素 x 推到队列的末尾 
#  int pop() 从队列的开头移除并返回元素 
#  int peek() 返回队列开头的元素 
#  boolean empty() 如果队列为空，返回 true ；否则，返回 false 
#  
# 
#  
# 
#  说明： 
# 
#  
#  你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
#  
#  你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。 
#  
# 
#  
# 
#  进阶： 
# 
#  
#  你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。 
#  
# 
#  
# 
#  示例： 
# 
#  
# 输入：
# ["MyQueue", "push", "push", "peek", "pop", "empty"]
# [[], [1], [2], [], [], []]
# 输出：
# [null, null, null, 1, 1, false]
# 
# 解释：
# MyQueue myQueue = new MyQueue();
# myQueue.push(1); // queue is: [1]
# myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
# myQueue.peek(); // return 1
# myQueue.pop(); // return 1, queue is [2]
# myQueue.empty(); // return false
#  
# 
#  
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= x <= 9 
#  最多调用 100 次 push、pop、peek 和 empty 
#  假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作） 
#  
#  Related Topics 栈 设计 
#  👍 287 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class MyQueue:
    """参考链接: https://leetcode-cn.com/problems/implement-queue-using-stacks/solution/shi-yong-liang-ge-zhan-yi-ge-zhuan-men-ru-dui-yi-g/"""

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stackPop = []
        self.stackPush = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.stackPush.append(x)         # 任何时候都可以push元素进来


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if len(self.stackPop) != 0:                          # 如果stackpop里面有元素，说明有之后push进队列的还没有pop出去，那么直接从这里pop
            return self.stackPop.pop()

        for _ in range(len(self.stackPush)):      # 如果stackpop里面没有元素，那么把当前stackpush里的元素全部倒入pop中
            self.stackPop.append(self.stackPush.pop())
        return self.stackPop.pop()


    def peek(self) -> int:
        """
        Get the front element.
        """
        if len(self.stackPop) != 0:  # 如果stackpop里面有元素，说明有之后push进队列的还没有pop出去，那么直接从这里取-1
            return self.stackPop[-1]

        for _ in range(len(self.stackPush)):  # 如果stackpop里面没有元素，那么把当前stackpush里的元素全部倒入pop中
            self.stackPop.append(self.stackPush.pop())
        return self.stackPop[-1]


    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        if len(self.stackPush) == 0 and len(self.stackPop) == 0: return True
        return False



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
# leetcode submit region end(Prohibit modification and deletion)
