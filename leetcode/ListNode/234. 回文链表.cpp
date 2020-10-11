// 请判断一个链表是否为回文链表。

// 示例 1:

// 输入: 1->2
// 输出: false
// 示例 2:

// 输入: 1->2->2->1
// 输出: true
// 进阶：
// 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/palindrome-linked-list
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// # time： o(n)
// # space: o(1)

// # 中点为头 进行翻转
// # 1.偶数情况
// #         mid
// # 1->2->3->3->2->1->N
// # 1->2->3->3<-2<-1
// #          |
// #          N
// # 2.奇数情况
// #      mid
// # 1->2->3->2->1->N
// # 1->2->3<-2<-1
// #       |
// #       N
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        // 快慢指针获得中点
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        // 中点为头 进行翻转
        ListNode* rightHead = reverseList(p1);
        p1 = head;
        p2 = rightHead;
        ListNode* p1_pre = nullptr;
        // 回文检测
        while (p1 && p2 && p1!=p2) {
            if (p1->val != p2->val) {
                return false;
            }
            p1_pre = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        // 恢复输入链表
        p1_pre->next = reverseList(rightHead);
        return true;
    }
    // 翻转链表
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* node = head;
        while (node->next) {
            ListNode* nextNode = node->next;
            node->next = nextNode->next;
            nextNode->next = head;
            head = nextNode;
        }
        return head;
    }
};
// # time： o(n)
// # space: o(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        vector<int> res;
        ListNode* node = head;
        while (node) {
            res.push_back(node->val);
            node = node->next;
        }
        vector<int> rrr(res.rbegin(), res.rend());
        return res == rrr;
    }
};