// 给定一个二叉树，返回它的 后序 遍历。

// 示例:

// 输入: [1,null,2,3]  
//    1
//     \
//      2
//     /
//    3 

// 输出: [3,2,1]
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postOrder(root, res);
        return res;
    }
    void postOrder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return;

        postOrder(root->left, res);
        postOrder(root->right, res);
        res.push_back(root->val);
    }

    // 迭代
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* prev = nullptr;

        TreeNode* node = root;
        while (node || !st.empty()) {
            while (node) {
                st.push(node);
                node = node->left;
            }

            node = st.top(); st.pop();
            if (node->right && node->right != prev) {
                st.push(node);
                node = node->right;
            } else {
                res.push_back(node->val);
                prev = node;
                node = nullptr;
            }
        }
        return res;
    }
};