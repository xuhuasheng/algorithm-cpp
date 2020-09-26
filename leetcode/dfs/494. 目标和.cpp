// 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

// 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

// 示例：

// 输入：nums: [1, 1, 1, 1, 1], S: 3
// 输出：5
// 解释：

// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3

// 一共有5种方法让最终目标和为3。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/target-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// dfs
// 时间复杂度：O(2^N)
// 空间复杂度：O(N)
class Solution {
public:
    int ans = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
        dfs(nums, 0, 0, S);
        return ans;

    }
    void dfs(vector<int>& nums, int depth, int sum, int target) {
        if (depth == nums.size()) {
            if (sum == target) {
                ans += 1;
                return;
            } 
        }
        else {
            dfs(nums, depth+1, sum-nums[depth], target);
            dfs(nums, depth+1, sum+nums[depth], target);
        }  
    }
};