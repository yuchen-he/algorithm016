/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 两个一组反转：主要是建立一个preNode，然后first和second交换，preNode移动至交换后的first
        // 1. 迭代法：
        //    每k个一组，当成反转链表来做，但是需要一个preNode
    }
};
// @lc code=end

