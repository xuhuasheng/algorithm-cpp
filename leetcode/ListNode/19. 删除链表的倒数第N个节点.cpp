// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

// 示例：

// 给定一个链表: 1->2->3->4->5, 和 n = 2.

// 当删除了倒数第二个节点后，链表变为 1->2->3->5.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 快慢指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        // 快指针提前n步
        while (n--) {
            p1 = p1->next;
        }
        if (p1 == nullptr) {
            // 快指针到头了，即倒数第n个就是第一个元素
            head = head->next;
        } else {
            // 快指针没到头，此时快慢指针同时移动
            while (p1->next) {
                p1 = p1->next;
                p2 = p2->next;
            }
            // 此时慢指针指向要删除元素的前一个元素
            p2->next = p2->next->next; 
        }
        return head;
    }
};