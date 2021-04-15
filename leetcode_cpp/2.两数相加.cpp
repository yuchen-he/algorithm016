/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /**
         * 改进方法1. 第一个循环的条件用或，然后里面分别判断l1和l2是否为空，不为空才加上它的val
         * 改进方法2. 先把l1和l2对齐补0，然后只需要用1个循环
        */
        /**
         * 会有几种情况:
         *  1. l1和l2长度相等
         *      1.1. 最后一位相加之后有进位
         *      1.2. 最后一位相加之后没有进位
         *  2. l1和l2长度不相等
         *      2.1. l1更长: 需要把l1剩余的再加完，并且也会分为最后一位有没有进位
         *      2.2. l2更长: 需要把l2剩余的再加完，并且也会分为最后一位有没有进位
        */
        ListNode* head = new ListNode();
        ListNode* cur = head;
        int curSum = 0, preSum = 0;
        while (l1 != NULL && l2 != NULL) {
            curSum = l1->val + l2->val + preSum;
            cur->val = curSum % 10;
            preSum = curSum / 10;      // 代表进位的数字

            l1 = l1->next;
            l2 = l2->next;
            if (preSum != 0 || (l1 != NULL || l2 != NULL)) {
                // 需要创建next节点的条件: 1. 有进位(如9+9)  2. l1或者l2不为空(如23+1)
                cur->next = new ListNode();
                cur = cur->next;
            } 
        }

        while (l1 != NULL) {
            // l1比l2长的情况
            curSum = l1->val + preSum;
            cur->val = curSum % 10;
            preSum = curSum / 10;

            l1 = l1->next;
            if (preSum != 0 || l1 != NULL) {
                cur->next = new ListNode();
                cur = cur->next;
            } 
        }

        while (l2 != NULL) {
            // l2比l1长的情况
            curSum = l2->val + preSum;
            cur->val = curSum % 10;
            preSum = curSum / 10;

            l2 = l2->next;
            if (preSum != 0 || l2 != NULL) {
                cur->next = new ListNode();
                cur = cur->next;
            } 
        }

        // 最后还有进位的情况
        if (preSum != 0) cur->val = preSum;
        return head;
    }
};
// @lc code=end

