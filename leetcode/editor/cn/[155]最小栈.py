# 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。 
# 
#  
#  push(x) —— 将元素 x 推入栈中。 
#  pop() —— 删除栈顶的元素。 
#  top() —— 获取栈顶元素。 
#  getMin() —— 检索栈中的最小元素。 
#  
# 
#  
# 
#  示例: 
# 
#  输入：
# ["MinStack","push","push","push","getMin","pop","top","getMin"]
# [[],[-2],[0],[-3],[],[],[],[]]
# 
# 输出：
# [null,null,null,null,-3,null,0,-2]
# 
# 解释：
# MinStack minStack = new MinStack();
# minStack.push(-2);
# minStack.push(0);
# minStack.push(-3);
# minStack.getMin();   --> 返回 -3.
# minStack.pop();
# minStack.top();      --> 返回 0.
# minStack.getMin();   --> 返回 -2.
#  
# 
#  
# 
#  提示： 
# 
#  
#  pop、top 和 getMin 操作总是在 非空栈 上调用。 
#  
#  Related Topics 栈 设计 
#  👍 667 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class MinStack:

    # 单一栈法：
    # 目的：只用一个变量来保存最小值
    # 难点：这样做的话在于，栈顶元素对应的最小值虽然可以保存，一旦pop了之后，前一个元素对应的最小值就丢失了
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.min_val = math.inf
        self.stack = []

    def push(self, x: int) -> None:
        if x <= self.min_val:                 # 这个<=关键，因为栈内可能有几个跟min相等的元素(纸上画一下)
            self.stack.append(self.min_val)   # 这一步是重点：当min更新时，先把之前的min压入栈中
            self.min_val = x
        self.stack.append(x)

    def pop(self) -> None:
        if self.stack[-1] == self.min_val:
            self.stack.pop()
            self.min_val = self.stack.pop()   # 注意点：如果pop的是min_value，则需要更新min_value
        else: self.stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_val


    # 辅助栈法：时间O(1),空间O(n)
    # def __init__(self):
    #     """
    #     initialize your data structure here.
    #     """
    #     # 利用一个minStack辅助栈，对于stack中的任一元素：
    #     # 当其作为栈顶元素存留在stack中时，在minStack中保存该元素对应的栈内最小值（即它往下的所有元素中的最小值）
    #     self.stack = []
    #     self.minStack = [float('inf')]   # or [math.inf]
    #
    # def push(self, x: int) -> None:
    #     self.stack.append(x)
    #     self.minStack.append(min(x, self.minStack[-1]))
    #
    # def pop(self) -> None:
    #     self.stack.pop()
    #     self.minStack.pop()
    #
    # def top(self) -> int:
    #     return self.stack[-1]
    #
    # def getMin(self) -> int:
    #     return self.minStack[-1]




# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# leetcode submit region end(Prohibit modification and deletion)
