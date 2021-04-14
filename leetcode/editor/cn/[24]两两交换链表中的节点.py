# 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。 
# 
#  你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
# 
#  
# 
#  示例: 
# 
#  给定 1->2->3->4, 你应该返回 2->1->4->3.
#  
#  Related Topics 链表 
#  👍 620 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        # ListNode pre(None)    # 这是c++的定义方式
        pre = ListNode(None)
        pre.next = head
        ret = pre
        # ret = pre.next.next    # 空链表进来的话没有.next，会出错

        while pre.next and pre.next.next:
            first = pre.next
            second = pre.next.next

            first.next = second.next
            second.next = first
            pre.next = second

            pre = first

        return ret.next
# leetcode submit region end(Prohibit modification and deletion)
