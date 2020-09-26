// 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

// 说明：

// 所有数字都是正整数。
// 解集不能包含重复的组合。 
// 示例 1:

// 输入: k = 3, n = 7
// 输出: [[1,2,4]]
// 示例 2:

// 输入: k = 3, n = 9
// 输出: [[1,2,6], [1,3,5], [2,3,4]]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/combination-sum-iii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> track;
        vector<vector<int>> res;
        dfs(k, 1, n, track, res);
        return res;
    }

    void dfs(int size, int begin, int target, vector<int>& track, vector<vector<int>>& res) {
        if (track.size() == size && target == 0) {
            res.push_back(track);
            return;
        }
        for (int i=begin; i<=9; i++) {
            // 剪枝
            if (target - i < 0) {
                break;
            }
            track.push_back(i);
            dfs(size, i+1, target-i, track, res);
            track.pop_back();
        }
    }
};