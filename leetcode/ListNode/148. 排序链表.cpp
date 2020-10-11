// 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

// 示例 1:

// 输入: 4->2->1->3
// 输出: 1->2->3->4
// 示例 2:

// 输入: -1->5->3->4->0
// 输出: -1->0->3->4->5

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/sort-list
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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

// time: o(nlogn)归并排序
// space:o(logn) 递归用了栈空间
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 递归终止条件：节点为空 或 只有一个节点
        if (head == nullptr || head->next == NULL) {
            return head;
        }
        // 获得链表的中间节点
        ListNode* midNode = getMidNode(head);
        // 分割为左右2个子链表
        ListNode* rightHead = midNode->next;
        midNode->next = NULL;
        // 递归排序左右2个子链表
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);
        // 合并两个有序链表
        return mergeTwoLists(left, right);
    }
    // 876. 链表的中间结点
    ListNode* getMidNode(ListNode* head) {
        if (head == nullptr || head->next == NULL) {
            return head;
        }
        // 注意这里快指针p2的初始化，
        // 当节点个数为奇数时，返回中间节点前一个
        // 当节点个数为偶数时，返回中间位置前一个
        ListNode* p1 = head;
        ListNode* p2 = head->next->next;  
        // ===============================  
        // ListNode* p1 = head;
        // ListNode* p2 = head;  
        // 如果如上初始化快指针p2，
        // 当节点个数为奇数时，返回中间节点
        // 当节点个数为偶数时，返回中间位置后一个
        // ===============================
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }
    
    // LC21.合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* head = new ListNode(-1);
        ListNode* node = head;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                node->next = p1;
                p1 = p1->next;
            } else {
                node->next = p2;
                p2 = p2->next;
            }
            node = node->next;
        }
        node->next = p1 ? p1 : p2;
        return head->next;
    }
};