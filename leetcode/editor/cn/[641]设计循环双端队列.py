# 设计实现双端队列。 
# 你的实现需要支持以下操作： 
# 
#  
#  MyCircularDeque(k)：构造函数,双端队列的大小为k。 
#  insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。 
#  insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。 
#  deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。 
#  deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。 
#  getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。 
#  getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。 
#  isEmpty()：检查双端队列是否为空。 
#  isFull()：检查双端队列是否满了。 
#  
# 
#  示例： 
# 
#  MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
# circularDeque.insertLast(1);			        // 返回 true
# circularDeque.insertLast(2);			        // 返回 true
# circularDeque.insertFront(3);			        // 返回 true
# circularDeque.insertFront(4);			        // 已经满了，返回 false
# circularDeque.getRear();  				// 返回 2
# circularDeque.isFull();				        // 返回 true
# circularDeque.deleteLast();			        // 返回 true
# circularDeque.insertFront(4);			        // 返回 true
# circularDeque.getFront();				// 返回 4
#   
# 
#  
# 
#  提示： 
# 
#  
#  所有值的范围为 [1, 1000] 
#  操作次数的范围为 [1, 1000] 
#  请不要使用内置的双端队列库。 
#  
#  Related Topics 设计 队列 
#  👍 57 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class MyCircularDeque:
    # 循环双端队列
    # 如果用python数组的insert和pop方法可以很容易实现，但是insertFront()操作会变成O(N)
    # 所以这道题本意是要实现所有方法都是O(1)复杂度的
    # 例如k=4时，先插10,20,30，然后要在前面插入40时，不是insert(0,40),而应该时dequeue[3]=40（因为循环队列）
    # 因此，要有两个指针front和rear（rear的index可能在front前，因为循环队列）
    # front指向目前循环队列的第一个元素，back指向后一个可以插入的位置（与front不一样）

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        """
        self.cap = k + 1     # 为了判断full要浪费一个位置(rear始终指向空位置)，因此数组实际有k+1个位置
        self.dequeue = [0 for _ in range(self.cap+1)]    # 需要初始化，不然self.dequeue[0] = 1这种赋值会出错
        self.front = 0
        self.rear = 0

    def insertFront(self, value: int) -> bool:
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        """
        if not self.isFull():
            self.front = (self.front - 1 + self.cap) % self.cap    # 关键点：利用取模来处理index溢出
            self.dequeue[self.front] = value
            return True
        else:
            return False
        

    def insertLast(self, value: int) -> bool:
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        """
        if not self.isFull():
            self.dequeue[self.rear] = value
            self.rear = (self.rear + 1) % self.cap
            return True
        else:
            return False
        

    def deleteFront(self) -> bool:
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        """
        if not self.isEmpty():
            # del self.dequeue[self.front]     # 不需要进行del操作，只需改变指针就行。因为get函数只看指针。
            self.front = (self.front + 1) % self.cap
            return True
        else:
            return False
        

    def deleteLast(self) -> bool:
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        """
        if not self.isEmpty():
            self.rear = (self.rear - 1 + self.cap) % self.cap
            # del self.dequeue[self.rear]
            return True
        else:
            return False
        

    def getFront(self) -> int:
        """
        Get the front item from the deque.
        """
        if not self.isEmpty():
            return self.dequeue[self.front]
        else:
            return -1
        

    def getRear(self) -> int:
        """
        Get the last item from the deque.
        """
        if not self.isEmpty():
            return self.dequeue[(self.rear - 1 + self.cap) % self.cap ]
        else:
            return -1
        

    def isEmpty(self) -> bool:
        """
        Checks whether the circular deque is empty or not.
        """
        if self.front == self.rear:
            return True
        else:
            return False
        

    def isFull(self) -> bool:
        """
        Checks whether the circular deque is full or not.
        """
        if (self.rear+1) % self.cap == self.front:         # 关键点：因为实际上empty和full时，front和rear都是指向同一个位置。所以这里要设计浪费一个位置
            return True
        else:
            return False
        


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
# leetcode submit region end(Prohibit modification and deletion)
