/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    // ListNode* mergeList(ListNode* l1, ListNode* l2) {
    //     if (l1 == NULL) return l2;
    //     if (l2 == NULL) return l1;
    //     if (l1->val <= l2->val) {
    //         l1->next = mergeList(l1->next, l2);
    //         return l1;
    //     }
    //     else {
    //         l2->next = mergeList(l1, l2->next);
    //         return l2;
    //     }
    // }

    ListNode* sortList(ListNode* head) {
        /**
         * 解法三: 无递归，自底向上，直接合并 -> 空间复杂度O(1)
         * 因为归并有cut和merge两个过程，
        */
        // if 


        /**
         * 解法二: 优化以下两点（但分割链表时依然用到了递归，所以仍然是O(n)空间复杂度）
         * 1. 找链表的中点: 快慢指针法
         * 2. merge操作: 迭代，利用pre节点（不使用递归从而优化空间复杂度）
        */
        // if (head == nullptr || head->next == nullptr) return head;

        // // 优化1: 快慢指针，快指针走两步慢指针走一步，最终慢指针即为中点
        // ListNode* slow = head;
        // ListNode* fast = head->next;
        // while (fast != nullptr && fast->next != nullptr) {
        //     fast = fast->next->next;
        //     slow = slow->next;
        // }
        // ListNode* mid = slow->next;
        // slow->next = nullptr;

        // // 分割。依然用到递归
        // ListNode* left = sortList(head);
        // ListNode* right = sortList(mid);

        // // 优化2: merge使用迭代而非递归（优化空间复杂度）
        // ListNode* pre = new ListNode(0);
        // ListNode* res = pre;   // res用于返回（因为下面的while中pre的位置需要一直变化）
        // while (left != nullptr && right != nullptr) {
        //     if (left->val <= right->val) {
        //         pre->next = left;
        //         left = left->next;
        //     }
        //     else {
        //         pre->next = right;
        //         right = right->next;
        //     }
        //     pre = pre->next;
        // }
        // // 要注意！最后肯定有一边链表还有的，所以只需将pre指向剩下的链表头节点即可
        // pre->next = (left != nullptr) ? left : right;
        // return res->next;


        /**
         * 解法一: 递归法 -> 时间复杂度O(nlogn)，但是递归栈导致空间复杂度O(n)
        */
        // // terminator
        // if (head == nullptr || head->next == nullptr) return head;

        // // 找到中间位置
        // ListNode* left = head;
        // ListNode* right = head;
        // int count = 1;
        // while (head->next != nullptr) {
        //     head = head->next;
        //     count++;
        // }
        // int mid = 1;
        // while (mid < count / 2) {
        //     mid++;
        //     right = right->next;
        // }
        
        // // 一刀两断，并获取中间节点之后的那个节点指针
        // ListNode* tmp = right->next;
        // right->next = nullptr;
        // right = tmp;

        // // drill down，左右两边递归，预计返回的是排序好之后的左右两个链表
        // left = sortList(left);
        // right = sortList(right);

        // // merge == 合并两个有序链表(21题)
        // return mergeList(left, right);
    }
};
// @lc code=end

