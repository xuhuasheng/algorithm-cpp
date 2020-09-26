// 给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

// 示例:

// nums = [1, 2, 3]
// target = 4

// 所有可能的组合为：
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)

// 请注意，顺序不同的序列被视作不同的组合。

// 因此输出为 7。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/combination-sum-iv
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 1;
        for (int i=1; i<=target; i++) {
            for (int num : nums) {
                if (num <= i) {
                    dp[i] += dp[i-num];
                }
            }
        }
        return dp[target];
// dfs会超时
// 实际上是背包问题
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> track;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        dfs(nums, target, track, res);
        return res.size();
    }

    void dfs(vector<int>& nums, int target, vector<int>& track, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(track);
            return;
        }

        for (int i=0; i<nums.size(); i++) {
            if (target - nums[i] < 0) {
                break;
            }
            track.push_back(nums[i]);
            dfs(nums, target- nums[i], track, res);
            track.pop_back();
        }
    }
};


    }
};