// 给定一个数组 candidates 和一个目标数 target ，
// 找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的每个数字在每个组合中*只能使用一次*，*可能有重复的候选数*。

// 说明：

// 所有数字（包括目标数）都是正整数。
// 解集不能包含重复的组合。 
// 示例 1:

// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
// 所求解集为:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// 示例 2:

// 输入: candidates = [2,5,2,1,2], target = 5,
// 所求解集为:
// [
//   [1,2,2],
//   [5]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/combination-sum-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// https://leetcode-cn.com/problems/combination-sum-ii/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-3/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> track;
        int size = candidates.size();
        // 排序是剪枝的前提
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, size, target, track, res);
        return res;
    }
    void dfs(vector<int>& candidates, int begin, int size, int target, vector<int>& track, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(track);
            return;
        }

        for (int i=begin; i<size; i++) {
            // 大剪枝：减去 candidates[i] 小于 0，减去后面的肯定也小于 0，因此用 break
            if (target-candidates[i] < 0) {
                break;
            }
            // 小剪枝：同一层相同数值的结点，从第 2 个开始，候选数更少，结果一定发生重复，因此跳过，用 continue
            // 防止 [1, 2', 2''] 和 [1, 2'', 2']的重复
            // (题目特征：候选序列可包含重复数字)
            if (i>begin && candidates[i-1] == candidates[i]) {
                continue;
            }

            track.push_back(candidates[i]);
            // 因为元素不可以重复使用，这里递归传递下去的是 i + 1 而不是 i
            dfs(candidates, i+1, size, target-candidates[i], track, res);
            track.pop_back();
        }
    }
};