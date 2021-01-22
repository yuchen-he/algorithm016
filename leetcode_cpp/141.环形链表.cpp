/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        /* 快慢指针: 每轮移动之后两者的距离会加一（慢指针针每次走一步，快指针每次走两步）
        如果有环，则快指针一定会在某个时刻==慢指针
        */
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast!= nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};
// @lc code=end

