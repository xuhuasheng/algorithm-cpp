// 给定一个无序的整数数组，找到其中最长上升子序列的长度。

// 示例:

// 输入: [10,9,2,5,3,7,101,18]
// 输出: 4 
// 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
// 说明:

// 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
// 你算法的时间复杂度应该为 O(n2) 。
// 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
// 时间复杂度：o(n^2)
// # 动态规划：
// # 定义dp[n]：表示以nums[n]这个数结尾的最长递增子序列的长度
// # 递推公式：dp[i] = max(dp[j]+1)， for j in range(i) and nums[i] > nums[j]
// # 初始值：dp[0] = 1
// # 最终问题解：max(dp) dp缓存数组里的最大值即为最长上升子序列的长度
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n<=1) return n;
        vector<int> dp(n, 1);
        int res = 0;
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max(res, dp[i]);
        }
        // int max = 0;
        // for (int i=0; i<n; i++) {
        //     if (dp[i] > max) {
        //         max = dp[i];
        //     }
        // }
        return res;
    }
// 时间复杂度：o(nlogn)
// # 时间复杂度：o(nlogn)
// # https://blog.csdn.net/qq_41765114/article/details/88415541
// # 定义dp[n]：dp[i] 表示长度为 i 的最长递增子序列（LIS）末尾的数
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        if (n<=1) return n;
        vector<int> dp(n,0);
        int length = 0;
        for (int num : nums) {
            int left = 0;
            int right = length;
            // 二分法
            // 搜索区间 [left, right)
            while (left < right) {
                int mid = (left+right)/2;
                if (dp[mid] == num)
                    right = mid;
                else if (dp[mid] < num)
                    left = mid+1;
                else if (dp[mid] > num)
                    right = mid;
            }
            dp[left] = num;
            if (right == length) {
                length += 1;
            }
        }
        return length;
    }
};