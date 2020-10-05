// 给定一个二叉树，检查它是否是镜像对称的。

//  

// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//  

// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

//     1
//    / \
//   2   2
//    \   \
//    3    3

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/symmetric-tree
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
// 递归
// 时间复杂度为 O(n)
// 空间复杂度为 O(n)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 自己和自己互为镜像对称，则这个树为镜像对称的
        // 轴对称是镜像对称的特例
        return isMirror(root, root);
    }
    // 判断两个树是否互为镜像对称
    bool isMirror(TreeNode* root1, TreeNode* root2) {
        // 都为空的
        if (!root1 && !root2) return true;
        // 其中一个是空的
        if (!root1 || !root2) return false;
        // 两个都非空
        return (root1->val == root2->val) 
            && (isMirror(root1->left, root2->right))
            && (isMirror(root1->right, root2->left));
    }
};

// 迭代
// 时间复杂度为 O(n)
// 空间复杂度为 O(n)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 自己和自己互为镜像对称，则这个树为镜像对称的
        // 轴对称是镜像对称的特例
        return isMirror(root, root);
    }

    // 首先我们引入一个队列，这是把递归程序改写成迭代程序的常用方法。
    // 初始化时我们把根节点入队两次。每次提取两个结点并比较它们的值（队列中每两个连续的结点应该是相等的，而且它们的子树互为镜像），
    // 然后将两个结点的左右子结点按相反的顺序插入队列中。
    // 当队列为空时，或者我们检测到树不对称（即从队列中取出两个不相等的连续结点）时，该算法结束。
    bool isMirror(TreeNode* u, TreeNode* v) {
        queue<TreeNode*> q;
        q.push(u);
        q.push(v);
        while (!q.empty()) {
            u = q.front(), q.pop();
            v = q.front(), q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;
            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }
};