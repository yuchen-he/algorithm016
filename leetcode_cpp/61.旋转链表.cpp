/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        /**
         * 解法一: 快慢指针（一个到当前链表点末尾，一个到旋转后链表的末尾 = count-(k%count)）
        */
        if (k == 0 || head == nullptr) return head;
        ListNode* fast = head;
        ListNode* slow = head;

        int count = 1;
        while (fast->next != nullptr) {
            count++;
            fast = fast->next;
        }
        // 如果k是count的倍数，则链表不会旋转，所以直接返回
        if (k % count == 0) return head;

        for (int i = 1; i < (count - (k % count)); i++) {
            slow = slow->next;
        }

        ListNode* tmp = slow->next;
        slow->next = fast->next;
        fast->next = head;
        return tmp;
    }
};
// @lc code=end

