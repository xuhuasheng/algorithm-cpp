// 给定一个二叉树，原地将它展开为一个单链表。

//  

// 例如，给定二叉树

//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// 将其展开为：

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> list;
        preOrder(root, list);
        // 从第二个节点开始
        for (int i=1; i<list.size(); i++) {
            TreeNode* pre = list[i-1];
            TreeNode* cur = list[i];
            pre->left = NULL;
            pre->right = cur;
        }
    }
    // 前序遍历
    void preOrder(TreeNode* root, vector<TreeNode*>& list) {
        if (root == nullptr) return;
        list.push_back(root);
        preOrder(root->left, list);
        preOrder(root->right, list);
    }
};