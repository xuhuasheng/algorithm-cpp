// 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

// 注意:

// 每个数组中的元素不会超过 100
// 数组的大小不会超过 200
// 示例 1:

// 输入: [1, 5, 11, 5]

// 输出: true

// 解释: 数组可以分割成 [1, 5, 5] 和 [11].
//  

// 示例 2:

// 输入: [1, 2, 3, 5]

// 输出: false

// 解释: 数组不能分割成两个元素和相等的子集.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/partition-equal-subset-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 转化为01背包问题
// 给一个可装载重量为 sum / 2 的背包和 N 个物品，每个物品的重量为 nums[i]。
// 现在让你装物品，是否存在一种装法，能够恰好将背包装满？

// https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/0-1-bei-bao-wen-ti-bian-ti-zhi-zi-ji-fen-ge-by-lab/
// 二维dp
// 时间复杂度：O(NC)：这里 NN 是数组元素的个数，CC 是数组元素的和的一半。
// 空间复杂度：O(NC)。
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return false;
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        if (total % 2 != 0) return false;
        int sum = total / 2;
        // 1. 明确dp数组定义：dp[i][j] 表示在前i个物品中, 是否能够使容量为j的背包恰巧装满
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        // 2. base case：dp[..][0] = true 和 dp[0][..] = false，
        // 因为背包没有空间的时候，就相当于装满了，而当没有物品可选择的时候，肯定没办法装满背包
        for (int i=0; i<=n; i++) {
            dp[i][0] = true;
        }
        // 3. 填表
        // 注意：由于 i 是从 1 开始的，而数组索引是从 0 开始的，所以第 i 个物品的重量应该是 nums[i-1]，这一点不要搞混。
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=sum; j++) {
                // 背包容量不足，不能装入第 i 个物品
                if (j-nums[i-1] < 0) {
                    dp[i][j] = dp[i-1][j];
                }
                // 能装下：有2种选择：不装入或装入背包
                else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        // 4. 返回原问题
        return dp[n][sum];
    }

    // 状态压缩：二维到一维， 因为二维数组每一行的填表只依赖于上一行
    // 时间复杂度 O(n*sum)，空间复杂度 O(sum)
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        sum = sum / 2;

        // 一维dp数组
        vector<bool> dp(sum+1, false);
        // base case
        dp[0] = true;
        // 填表
        for (int i=0; i<n; i++) {   // 从i=0开始， 填n行
            for (int j=sum; j>=0; j--) {    // 注意填表顺序，反向填列，避免覆盖要用的历史数据
                // 如果能装下 
                if (j - nums[i] >= 0)
                    dp[j] = dp[j] || dp[j-nums[i]];
                // 装不下则不更新
            }
        }
        return dp[sum];
    }
};


