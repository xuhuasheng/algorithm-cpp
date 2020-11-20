// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

// 示例 1：

// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]
// 示例 2：

// 输入：head = []
// 输出：[]
// 示例 3：

// 输入：head = [1]
// 输出：[1]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
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

// 法1：递归
// time:  o(n)
// space: o(n) 栈空间
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head && head->next == nullptr) return head;
        ListNode* nextNode = head->next;
        head->next = swapPairs(nextNode->next);
        nextNode->next = head;
        return nextNode;
    }
};
// 法2：非递归
// time:  o(n)
// space: o(1) 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);  // 辅助头节点
        ListNode* prevNode = dummyHead;
        dummyHead->next = head;
        while (prevNode->next && prevNode->next->next) {
            // 交换前的两个节点
            ListNode* node1 = prevNode->next;
            ListNode* node2 = prevNode->next->next;
            // 提前连接
            prevNode->next = node2;
            // 交换
            node1->next = node2->next;
            node2->next = node1;
            // 更新前一个节点
            prevNode = node1;
        }
        return dummyHead->next;
    }
};