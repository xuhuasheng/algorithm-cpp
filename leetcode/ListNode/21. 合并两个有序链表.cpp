// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

//  

// 示例：

// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4

// // 来源：力扣（LeetCode）
// // 链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
// // 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
    // 非递归
    // 时间复杂度：o(m+n)
    // 空间复杂度：o(m+n) 
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if ((!l1) || (!l2)) return l1 ? l1 : l2;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* head = new ListNode(-1);
        ListNode* node = head;
        ListNode* temp;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                temp = new ListNode(p1->val);
                p1 = p1->next;
            } else {
                temp = new ListNode(p2->val);
                p2 = p2->next;
            }
            node->next = temp;
            node = temp;
        }
        node->next = (p1 ? p1 : p2);
        return head->next;
    }

    // 递归
    // https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/yi-kan-jiu-hui-yi-xie-jiu-fei-xiang-jie-di-gui-by-/
    // 时间复杂度：o(m+n)
    // 空间复杂度：o(m+n) (递归调用栈的空间)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }  
    }
};