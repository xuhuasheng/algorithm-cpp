// 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

// 说明: 叶子节点是指没有子节点的节点。

// 示例: 
// 给定如下二叉树，以及目标和 sum = 22，

//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/path-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        if (!root->left && !root->right && root->val == sum) {
            return true;
        }
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        stack<pair<TreeNode*, int>> st;
        st.push(pair<TreeNode*, int> (root, sum));
        while (!st.empty()) {
            pair<TreeNode*, int> p = st.top();
            st.pop();
            TreeNode* node = p.first;
            int path = p.second;
            if (!node->left && !node->right && path == sum) {
                return true;
            }
            if (node->left) {
                st.push(pair<TreeNode*, int> (node->left, path + node->left->val));
            }
            if (node->right) {
                st.push(pair<TreeNode*, int> (node->right, path + node->right->val));
            }
        }
        return false;
    }
};