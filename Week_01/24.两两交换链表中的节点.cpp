/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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

// 递归解法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 递归解法不需要preNode（全反转也是），因为递归返回时有前面两个元素的指针（first,second）

        // 终止条件
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // 这一步为了在递归返回时，便于写交换操作，从而设定first和second
        ListNode* first = head;
        ListNode* second = head->next;

        // 这一步要在纸上画，first指针永远是指向当前的第2n+1(奇数个元素)或2n+3(偶数个元素)个元素
        // 而swapParis触发终止条件返回的是指向NULL的指针(触发head == NULL,共偶数个元素时)，
        //                        或指向最后元素的指针(触发head->next == NULL,共奇数个元素时，比上面少一层递归)
        // 所以为了反转第2n+3个元素与NULL，或者第2n+1与第2n+2个元素，这里用first.next指向返回来的指针指向的元素
        first->next = swapPairs(head->next->next);
        second->next = first;

        //因为上一层的first->next要指向下一层反转后的first(即反转前的second)
        head = second;
        // 可以确定返回的是head，因为终止条件也是（可以用这个倒退上一步该做的事情）
        return head;
    }
};

// 迭代解法
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         // 关键思想：建立一个preNode，虽然表面上是两个一组交换，但是需要一个跟前面建立关系的话，实际上是3个一组进行交换
//         // 因为head要指向下一组要交换的第一个元素的话，但是这个元素的前一个元素要指向它的后一个元素
//         ListNode* pre = new ListNode(0);   // 不能是NULL，因为NULL没有next指针
//         pre->next = head;
//         ListNode* ret = pre;
//         // ListNode* ret = head->next;   //head->next, 这样写当空链表进来会出错，因为NULL没有next
        
//         while (pre->next && pre->next->next) {
//             ListNode* first = pre->next;
//             ListNode* second = pre->next->next;

//             // 关键代码
//             pre->next = second;         //实际上这一步使得最后ret->next得以指向原链表第二个数，并且一直不变(因为之后pre指向改变了不影响ret，但这一步的pre.next就是ret.next)
//             first->next = second->next;
//             second->next = first;
//             pre = first;
//         }

//         return ret->next;
//     }
// };
// @lc code=end

