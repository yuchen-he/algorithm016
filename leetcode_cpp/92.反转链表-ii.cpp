/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        /**
         * 解法一: 迭代+头插法
         * https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/java-shuang-zhi-zhen-tou-cha-fa-by-mu-yi-cheng-zho/
        */
        // ListNode* dummy = new ListNode(0);
        // dummy->next = head;
        // ListNode* pre = dummy;

        // // 将pre和cur先移动到m的前一个节点 & m节点
        // for (int i=0; i<m-1; i++) pre = pre->next;
        // ListNode* cur = pre->next;

        // for (int j=0; j<n-m; j++) {
        //     // 用j记数，表示要移动几次节点
        //     ListNode* tmp = cur->next;
        //     cur->next = tmp->next;
        //     tmp->next = pre->next;
        //     pre->next = tmp;
        // }
        // return dummy->next;

        /**
         * 解法二: 递归法
        */
    }
};
// @lc code=end

