/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 关键思想：建立一个preNode，虽然表面上是两个一组交换，但是需要一个跟前面建立关系的话，实际上是3个一组进行交换
        // 因为head要指向下一组要交换的第一个元素的话，但是这个元素的前一个元素要指向它的后一个元素
        ListNode* pre = new ListNode(0);   // 不能是NULL，因为NULL没有next指针
        pre->next = head;
        ListNode* ret = pre;
        // ListNode* ret = head->next;   //head->next, 这样写当空链表进来会出错，因为NULL没有next
        
        while (pre->next && pre->next->next) {
            ListNode* first = pre->next;
            ListNode* second = pre->next->next;

            // 关键代码
            pre->next = second;
            first->next = second->next;
            second->next = first;
            pre = first;
        }

        return ret->next;
    }
};
// @lc code=end

