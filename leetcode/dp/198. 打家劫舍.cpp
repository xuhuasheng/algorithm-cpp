// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
// 影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
//  
// 示例 1：

// 输入：[1,2,3,1]
// 输出：4
// 解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//      偷窃到的最高金额 = 1 + 3 = 4 。
// 示例 2：

// 输入：[2,7,9,3,1]
// 输出：12
// 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//      偷窃到的最高金额 = 2 + 9 + 1 = 12 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/house-robber
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 题解
// https://leetcode-cn.com/problems/house-robber/solution/dong-tai-gui-hua-jie-ti-si-bu-zou-xiang-jie-cjavap/
// 动态规划：
// 原问题：打劫n家
// 子问题：打劫前k家
// 递推公式：dp[k] = max(a[k]+dp[k-2], dp[k-1]) 决策是打不打第k家
// 初始条件：dp[0] = 0, dp[1] = a[0]
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int k=2; k<=n; k++) {
            dp[k] = std::max(nums[k-1]+dp[k-2], dp[k-1]);
        }
        return dp[n];
    }

    int rob2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int a = 0, b = nums[0];
        int ans = 0;
        for (int k=2; k<=n; k++) {
            ans = std::max(nums[k-1]+a, b);
            a = b;
            b = ans;
        }
        return ans;
};