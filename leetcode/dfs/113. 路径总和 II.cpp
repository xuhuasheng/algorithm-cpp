// 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

// 说明: 叶子节点是指没有子节点的节点。

// 示例:
// 给定如下二叉树，以及目标和 sum = 22，

//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// 返回:

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/path-sum-ii
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return {};
        vector<int> track;
        vector<vector<int>> res;
        track.push_back(root->val);
        dfs(root, sum, track, res);
        return res;
    }

    void dfs(TreeNode* root, int sum, vector<int>& track, vector<vector<int>>& res) {
        if (root == nullptr) return;
        if (!root->left && !root->right && root->val == sum) {
            res.push_back(track);
            return;
        }
        if (root->left) {
            sum -= root->val;
            track.push_back(root->left->val);
            dfs(root->left, sum, track, res);
            sum += root->val;
            track.pop_back();
        }
        if (root->right) {
            sum -= root->val;
            track.push_back(root->right->val);
            dfs(root->right, sum, track, res);
            sum += root->val;
            track.pop_back();
        }
    }
};