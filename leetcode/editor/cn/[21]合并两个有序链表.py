# 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
# 
#  
# 
#  示例： 
# 
#  输入：1->2->4, 1->3->4
# 输出：1->1->2->3->4->4
#  
#  Related Topics 链表 
#  👍 1302 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur = ListNode(-1)
        # 关键：cur与res指向同一块地址，这之后res指向位置变了，cur也不会变
        #      并且res更改了最开始的地址里的val和next，会导致cur指向的这块地址里的val和next也随着变（与24题一样）
        res = cur

        while (l1 and l2):
            if l1.val <= l2.val:
                res.next = l1
                l1 = l1.next
            else:
                res.next = l2
                l2 = l2.next
            res = res.next

        res.next = l1 if l1 else l2   # c++中用"cur->next = (l1 ? l1 : l2);"，速度快很多
        return cur.next
        
# leetcode submit region end(Prohibit modification and deletion)
