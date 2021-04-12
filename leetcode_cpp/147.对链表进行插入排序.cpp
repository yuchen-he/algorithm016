/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        // 解法二: head(prev)和head->next(cur)同时移动，这样prev就是已排序部分的最后一个节点了，不需要对pre一直while直到最后
        // 解法一: 自己想的，关键在于要移动某节点时，如何获取它的“前一个节点”
        ListNode* preHead = new ListNode(0, head);
        ListNode* cur = head;

        while (cur) {
            bool insertFlag = true;
            ListNode* pre = preHead;
            ListNode* tmp = cur->next;

            while (pre->next != cur) {
                if (insertFlag == true && pre->next->val >= cur->val) {
                    cur->next = pre->next;
                    // pre->next->next = tmp;       // 错误，因为如果插入位置不是已排序部分的最后的话，并不知道cur的前一个节点的位置
                    pre->next = cur;
                    insertFlag = false;          // 设置为false之后，就不会插入而已一直找到已排序部分的最后一个节点
                }
                pre = pre->next;
            }

            // cur被插入到前面的情况时，需要使已排序部分的最后一个节点与tmp连接。
            // 如果cur的位置没有动，则不需要改变任何
            if (insertFlag == false) pre->next = tmp;
            cur = tmp;
        }

        return preHead->next;
    }
};
// @lc code=end

