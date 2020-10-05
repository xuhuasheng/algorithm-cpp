// 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

//  

// 示例 1:

// 输入: [3,0,1]
// 输出: 2
// 示例 2:

// 输入: [9,6,4,2,3,5,7,0,1]
// 输出: 8

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/missing-number
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 法1 求和公式
        int n = nums.size();
        int sum = n * (n+1) / 2;
        int total = 0;
        for (int& num : nums) {
            total += num;
        }
        return sum - total;
        // =================================
        // 法2 位运算
        int res = nums.size();
        for (int i=0; i<nums.size(); i++) {
            res ^= (i ^ nums[i]);
        }
        return res;
    }
};