// 根据一棵树的前序遍历与中序遍历构造二叉树。

// 注意:
// 你可以假设树中没有重复的元素。

// 例如，给出

// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
// 返回如下的二叉树：

//     3
//    / \
//   9  20
//     /  \
//    15   7

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
        
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        // 寻找root在中序遍历中的索引
        // 注意在vector里找元素并返回索引
        vector<int>::iterator inorder_it = find(inorder.begin(), inorder.end(), rootVal);
        int leftNum = distance(inorder.begin(), inorder_it);
        
        // 找左右子树对应的前、中序序列
        // 注意vector的切片操作（使用待切片vector的迭代器指向切片的区间（左开右闭））
        vector<int> left_preorder(preorder.begin()+1, preorder.begin()+1+leftNum);
        vector<int> left_inorder(inorder.begin(), inorder.begin()+leftNum);

        vector<int> right_preorder(preorder.begin()+1+leftNum, preorder.end());
        vector<int> right_inorder(inorder.begin()+leftNum+1, inorder.end());

        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);
        return root;
    }
};