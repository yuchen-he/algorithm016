/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
         * 解法一: 利用栈（第2题两数相加1也可以用该套路，不过是利用列队）
         * 优化方法: 在生成输出链表时，利用“头插法”解决
        */
        stack<int> st1;
        stack<int> st2;

        while (l1 != NULL) {
            st1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != NULL) {
            st2.push(l2->val);
            l2 = l2->next;
        }

        // stack<int> st3;
        ListNode* pre = new ListNode();
        int sumOver = 0;
        while (!st1.empty() || !st2.empty() || sumOver != 0) {
            int val1 = 0, val2 = 0;
            if (!st1.empty()) {
                val1 = st1.top();
                st1.pop();
            }
            if (!st2.empty()) {
                val2 = st2.top();
                st2.pop();
            }

            // "头插法"
            ListNode* newNode = new ListNode();
            newNode->val = (val1 + val2 + sumOver) % 10;
            ListNode* tmp = pre->next;
            pre->next = newNode;
            newNode->next = tmp;

            // st3.push((val1 + val2 + sumOver) % 10);
            sumOver = (val1 + val2 + sumOver) / 10;
        }

        // 下面这一段优化方法在上面: 利用“头插法”
        // ListNode* head = new ListNode();
        // ListNode* cur = head;
        // while (!st3.empty()) {
        //     cur->val = st3.top();
        //     st3.pop();
        //     if (!st3.empty()) {
        //         ListNode* tmp = new ListNode();
        //         cur->next = tmp;
        //         cur = tmp;
        //     }
        // }
        // return head;

        return pre->next;
    }
};
// @lc code=end

