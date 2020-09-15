// 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

// candidates 中的数字可以无限制重复被选取。

// 说明：

// 所有数字（包括 target）都是正整数。
// 解集不能包含重复的组合。 
// 示例 1：

// 输入：candidates = [2,3,6,7], target = 7,
// 所求解集为：
// [
//   [7],
//   [2,2,3]
// ]
// 示例 2：

// 输入：candidates = [2,3,5], target = 8,
// 所求解集为：
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/combination-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> track;

        dfs(candidates, 0, candidates.size(), target, track, res);
        return res;

    }

    void dfs(vector<int>& candidates, int begin, int size, int target, vector<int>& track, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(track);
            return;
        }
        if (target < 0) return;

        for (int i=begin; i<size; i++) {
            track.push_back(candidates[i]);
            // 注意：由于每一个元素可以重复使用，下一轮搜索的起点依然是 i，这里非常容易弄错
            dfs(candidates, i, size, target-candidates[i], track, res);
            track.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> track;
        // 剪枝的前提 先排序====================
        sort(candidates.begin(), candidates.end());
        // ====================================
        dfs(candidates, 0, candidates.size(), target, track, res);
        return res;

    }

    void dfs(vector<int>& candidates, int begin, int size, int target, vector<int>& track, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(track);
            return;
        }
        for (int i=begin; i<size; i++) {
            // 提前剪枝 因为candidates已经排为了升序，
            // 当target-candidates[i] < 0时，for循环后面的target-candidates[i]也是小于0，所以可以提前跳出循环
            if (target-candidates[i] < 0) {
                break;
            }
            // ===========================
            track.push_back(candidates[i]);
            // 注意：由于每一个元素可以重复使用，下一轮搜索的起点依然是 i，这里非常容易弄错
            dfs(candidates, i, size, target-candidates[i], track, res);
            track.pop_back();
        }
    }
};

// 什么时候使用 used 数组，什么时候使用 begin 变量
// 有些朋友可能会疑惑什么时候使用 used 数组，什么时候使用 begin 变量。这里为大家简单总结一下：

// 排列问题，讲究顺序（即 [2, 2, 3] 与 [2, 3, 2] 视为不同列表时），需要记录哪些数字已经使用过，此时用 used 数组；
// 组合问题，不讲究顺序（即 [2, 2, 3] 与 [2, 3, 2] 视为相同列表时），需要按照某种顺序搜索，此时使用 begin 变量。
// 注意：具体问题应该具体分析， 理解算法的设计思想 是至关重要的，请不要死记硬背。
