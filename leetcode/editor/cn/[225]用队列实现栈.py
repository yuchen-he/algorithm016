# 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通队列的全部四种操作（push、top、pop 和 empty）。 
# 
#  实现 MyStack 类： 
# 
#  
#  void push(int x) 将元素 x 压入栈顶。 
#  int pop() 移除并返回栈顶元素。 
#  int top() 返回栈顶元素。 
#  boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。 
#  
# 
#  
# 
#  注意： 
# 
#  
#  你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。 
#  你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。 
#  
# 
#  
# 
#  示例： 
# 
#  
# 输入：
# ["MyStack", "push", "push", "top", "pop", "empty"]
# [[], [1], [2], [], [], []]
# 输出：
# [null, null, null, 2, 2, false]
# 
# 解释：
# MyStack myStack = new MyStack();
# myStack.push(1);
# myStack.push(2);
# myStack.top(); // 返回 2
# myStack.pop(); // 返回 2
# myStack.empty(); // 返回 False
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= x <= 9 
#  最多调用100 次 push、pop、top 和 empty 
#  每次调用 pop 和 top 都保证栈不为空 
#  
# 
#  
# 
#  进阶：你能否实现每种操作的均摊时间复杂度为 O(1) 的栈？换句话说，执行 n 个操作的总时间复杂度 O(n) ，尽管其中某个操作可能需要比其他操作更长的
# 时间。你可以使用两个以上的队列。 
#  Related Topics 栈 设计 
#  👍 284 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class MyStack:
    """
    解法二: push时候做文章。
    每次push时，都push到q2（每次完成push操作后要保证q2为空），然后把q1中的元素依次append到q2，然后q1和q2交换（这样q2为空，q1为逆序）
    """
    """
    解法一
    1. push都往q1里面push
    2. pop时
       2.1 如果q1长度n大于1，则把前n-1个元素push到q2中，然后popleft给返回值
       2.2 如果q1长度n等于1，则直接popleft
       2.3 如果q1长度n等于0，则把q1和q2交换，然后按照2.1的规则做（这一步可以替换为: 在每次执行了2.1之后就把q1和q2交换）

    """

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = collections.deque()
        self.q2 = collections.deque()


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q1.append(x)



    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if self.empty(): return None
        if len(self.q1) > 1:
            for _ in range(len(self.q1) - 1):
                self.q2.append(self.q1.popleft())
        res = self.q1.popleft()                           # q1清空了
        self.q1, self.q2 = self.q2, self.q1               # q1和q2互换，以便下次pop或者push都从q1开始判断
        return res

    def top(self) -> int:
        """
        Get the top element.
        """
        if self.empty(): return None
        if len(self.q1) > 1:
            for _ in range(len(self.q1) - 1):
                self.q2.append(self.q1.popleft())
        res = self.q1.popleft()
        self.q2.append(res)                               # 因为是top，所以把res再放入q2中
        self.q1, self.q2 = self.q2, self.q1               # q1和q2互换，以便下次pop或者push都从q1开始判断
        return res


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.q1) == 0 and len(self.q2) == 0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
# leetcode submit region end(Prohibit modification and deletion)
