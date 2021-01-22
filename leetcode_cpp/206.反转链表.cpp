/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        //递归解法：https://leetcode-cn.com/problems/reverse-linked-list/solution/dong-hua-yan-shi-206-fan-zhuan-lian-biao-by-user74/

        //终止条件：遍历到链表尾部 -> head.next = NULL
        if (head == NULL || head->next == NULL) {
            return head;
        }

        //递归处理
        // 首先会一直传入head.next调用递归至链表尾部，直至触发终止条件，从而返回head
        // (传入的head.next在函数里赋值给了head，触发head.next == NULL)
        // (所以在倒数第二层中，返回的head等同于head.next(即最后一个元素)，而该层的head是倒数第二个元素 )
        // 得到返回的head(即当前层的head.next)后，应该让当前层的head.next.next(即cur.next)指向head指向的元素，完成反转
        // 但此时head.next还是指向后一个元素（后一个元素在反转后指向当前head指向的元素，即循环指向）
        // 所以让head.next = NULL（防止循环指向）
        // 然后返回cur：cur一直指向原始链表的最后一个元素，这样的话递归完的cur就是指向反转后的链表首元素了。
        ListNode* cur = reverseList(head->next);
        head->next->next = head;     // 关键点：让该层的head指向元素的下一个元素反指回它的前一个元素
        head->next = NULL;
        return cur;

        // 错误解法
        // ListNode* curr = reverseList(head->next);
        // head->next = curr->next;
        // curr->next = head;
        // return head;       // 这个地方在最后会返回节点1（应该要返回5）
    }
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         // 迭代解法
//         // 返回值: 指向“反转之后的链表的最后一个元素”的指针
//         // pre:指向前一个元素的指针
//         // cur:指向当前元素的指针
//         // cur.next:指向后一个元素的指针
//         ListNode* pre = NULL;  //因为反转后要让原来的第一个元素指向NULL，所以先建立一个pre，并且为NULL
//         ListNode* cur = head;

//         while (cur != NULL) {
//             // 有上面这三个指针就有了前/中/后三个元素，但是还需要一个temp，来保存cur.next
//             // 因为每次要把cur.next指向前一个元素去，即cur.next=pre，所以需要temp以防后一个元素丢失
//             ListNode* temp = cur->next;
//             cur->next = pre;
            
//             pre = cur;    // pre移动到当前元素
//             cur = temp;   // cur移动到后一个元素
//         }
//         return pre;  //注意return的是pre（cur已经在32行被赋值为NULL了，也正因为这个while循环才得以结束）
//     }
// };
// @lc code=end

