// 给定一个二叉树，返回它的 前序 遍历。

//  示例:

// 输入: [1,null,2,3]  
//    1
//     \
//      2
//     /
//    3 

// 输出: [1,2,3]
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal
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
    // 递归
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preOrder(root, res);
        return res;
    }
    void preOrder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->val);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }
    // 迭代
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        stack<TreeNode*> st;
        vector<int> res;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            if (node) {
                res.push_back(node->val);
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
            }
        }
        return res;
    }
};