// 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

// 示例:

// 输入: n = 4, k = 2
// 输出:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/combinations
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// https://leetcode-cn.com/problems/combinations/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-ma-/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> track;
        dfs(n, k, 1, track, res);
        return res;
    }

    void dfs(int n, int k, int begin, vector<int>& track, vector<vector<int>>& res) {
        if (track.size() == k) {
            res.push_back(track);
            return;
        }
        // # 剪枝 设置了for 循环上限
        int end = n-(k-track.size())+1;
        for (int i=begin; i<=end; i++) {
        // for (int i=begin; i<=n; i++) {   //无剪枝
            track.push_back(i);
            dfs(n, k, i+1, track, res);
            track.pop_back();
        }
    }
};