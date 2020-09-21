// 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

//  

// 示例：

// 输入：s = 7, nums = [2,3,1,2,4,3]
// 输出：2
// 解释：子数组 [4,3] 是该条件下的长度最小的子数组。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// https://leetcode-cn.com/problems/minimum-size-subarray-sum/solution/chang-du-zui-xiao-de-zi-shu-zu-by-leetcode-solutio/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n==0) {
            return 0;
        }
        int start = 0;
        int end = 0;
        int sum = 0;
        int ans = n+1;
        while (end<n) {
            sum += nums[end];
            while (sum >= s) {
                ans = min(ans, end-start+1);
                sum -= nums[start];
                start += 1;
            }
            end += 1;
        }
        if (ans == n+1) return 0;
        return ans;
    }
};