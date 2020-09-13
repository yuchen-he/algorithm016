/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        // 返回值: 指向“反转之后的链表的最后一个元素”的指针
        // pre:指向前一个元素的指针
        // cur:指向当前元素的指针
        // cur.next:指向后一个元素的指针
        ListNode* pre = NULL;
        ListNode* cur = head;

        while (cur != NULL) {
            // 有上面这三个指针就有了前/中/后三个元素，但是还需要一个temp，来保存cur.next
            // 因为每次要把cur.next指向前一个元素去，即cur.next=pre，所以需要temp以防后一个元素丢失
            ListNode* temp = cur->next;
            cur->next = pre;
            
            pre = cur;    // pre移动到当前元素
            cur = temp;   // cur移动到后一个元素
        }
        return pre;  //注意return的是pre（cur已经在32行被赋值为NULL了，也正因为这个while循环才得以结束）
    }
};
// @lc code=end

