/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        /**快慢指针解法
         * https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
         * 重点关注慢指针！！！
         * 假设: 入环前共a个节点，环（包括入口）共b个节点
         * 1. 第一次相遇时，快指针比慢指针多走一个环的节点数 & 总步数是慢指针的2倍-> 慢指针此时走了nb个节点
         * 2. 重新定义一个指针从head开始走，直到与慢指针相遇 -> 此时新指针正好走a步，相遇点正好是入口（因为走到环入口时的总步数必然是a+nb步）
        */
        if (head == NULL || head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        
        // 第一次相遇: 慢指针总共走了nb个节点（包括不在环中的a个节点）
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                // 第二次相遇: 让head走过a个节点到达环入口，此时slow也会正好到达入口相遇
                while (head != slow) {
                    head = head->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
// @lc code=end

