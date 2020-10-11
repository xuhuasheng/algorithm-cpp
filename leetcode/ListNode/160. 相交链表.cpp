// 编写一个程序，找到两个单链表相交的起始节点。

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
    // 双指针交替游走
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1 != p2) {
            // 如果 pA 到了末尾，则 pA = headB 继续遍历
            // 如果 pB 到了末尾，则 pB = headA 继续遍历
            p1 = (p1 == NULL) ? headB : p1->next;
            p2 = (p2 == NULL) ? headA : p2->next;
        }
        return p1;
    }
    // 双指针异步游走
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        int lenA = 0;
        int lenB = 0;
        // headA的长度
        while (p1) {
            lenA++;
            p1 = p1->next;
        }
        // headB的长度
        while (p2) {
            lenB ++;
            p2 = p2->next;
        }
        // 长的那一条先走diff步
        p1 = headA;
        p2 = headB;
        int diff = abs(lenA - lenB);
        if (lenA > lenB) {
            while (diff--) {
                p1 = p1->next;
            }
        } else if (lenA < lenB) {
            while (diff--) {
                p2 = p2->next;
            }
        }
        // 再一起走
        while (p1 && p2) {
            if (p1 == p2) {
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return nullptr;
    }
};