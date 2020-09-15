// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

//  

// 示例：

// 输入：n = 3
// 输出：[
//        "((()))",
//        "(()())",
//        "(())()",
//        "()(())",
//        "()()()"
//      ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/generate-parentheses
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// 题解 https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/he-fa-kuo-hao-sheng-cheng
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n==0) return {};
        // 记录所有合法的括号组合
        vector<string> res;
        // 回溯过程中的路径
        string track;
        // 可用的左括号和右括号数量初始化为 n
        dfs(n, n, track, res);
        return res;
    }
    // 可用的左括号数量为 left 个，可用的右括号数量为 rgiht 个
    void dfs(int left, int right, string& track, vector<string>& res) {
        // 若左括号剩下的多，说明不合法
        if (right < left) return;
        // 数量小于 0 肯定是不合法的
        if (left < 0 || right < 0) return;
        // 当所有括号都恰好用完时，得到一个合法的括号组合
        if (left == 0 && right == 0) {
            res.push_back(track);
            return;
        }
        // 尝试放一个左括号
        track.push_back('(');// 选择
        dfs(left-1, right, track, res);
        track.pop_back();// 撤消选择
        // 尝试放一个右括号
        track.push_back(')');// 选择
        dfs(left, right-1, track, res);
        track.pop_back();// 撤消选择
    }
};