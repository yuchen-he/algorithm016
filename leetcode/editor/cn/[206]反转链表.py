# 反转一个单链表。 
# 
#  示例: 
# 
#  输入: 1->2->3->4->5->NULL
# 输出: 5->4->3->2->1->NULL 
# 
#  进阶: 
# 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？ 
#  Related Topics 链表 
#  👍 1216 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        pre = None                   # 不需要写ListNode
        cur = head

        while cur:                   # while (cur.val != None)出错，因为None没有.val
            temp = cur.next          # 不需要写ListNode temp
            cur.next = pre
            pre = cur
            cur = temp
        return pre
# leetcode submit region end(Prohibit modification and deletion)
