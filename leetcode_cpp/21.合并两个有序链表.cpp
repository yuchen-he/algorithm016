/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 递归解法（迭代解法在python）

        // terminator
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        // process & drill down
        if (l1->val <= l2->val) {
            // 关键点
            // 当l1更小时，应该返回l1给上一层.
            // 并且接下来l1->next指向的值并不确定，要对比l1->next和l2才知道。
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
// @lc code=end

