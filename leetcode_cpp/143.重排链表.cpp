/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        /**
         * 解法一: 快慢指针找到中点，反转后半部分，然后依次连接前半和后半的节点
         * 知识点: 快慢指针找中点，链表反转，合并两个链表
         * 参考官方题解: https://leetcode-cn.com/problems/reorder-list/solution/zhong-pai-lian-biao-by-leetcode-solution/
        */
        if (head == NULL || head->next == NULL || head->next->next == NULL) return;

        ListNode* fast = head;
        ListNode* slow = head;
        // step1: 快慢指针找到中间检点
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 此时slow的位置: 1. 共奇数个节点时为正中间 2. 共偶数个节点时为n/2-1
        // step2: 将slow的之后所有节点与前半部分分开，并且进行全反转
        ListNode* rightHead = slow->next;
        slow->next = NULL;

        ListNode* pre = new ListNode(0);
        pre->next = rightHead;
        while (rightHead->next != NULL) {
            ListNode* tmp = rightHead->next;
            rightHead->next = tmp->next;

            tmp->next = pre->next;
            pre->next = tmp;
        }

        // step3: 合并两个链表的操作
        ListNode* left = head;
        ListNode* right = pre->next;
        while (left != NULL && right != NULL) {
            ListNode* tmpLeft = left->next;
            ListNode* tmpRight = right->next;

            left->next = right;
            left = tmpLeft;
            
            right->next = left;
            right = tmpRight;
        }
    }
};
// @lc code=end

