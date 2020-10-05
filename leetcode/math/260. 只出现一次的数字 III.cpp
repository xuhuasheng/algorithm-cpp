// 给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

// 示例 :

// 输入: [1,2,1,3,2,5]
// 输出: [3,5]
// 注意：

// 结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
// 你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/single-number-iii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 1.全体异或
        int tmp = 0;
        for (int num : nums) tmp ^= num;
        // 2.异或结果的某一位差异
        long long pulse = 1;
        while ((tmp & pulse) == 0) pulse <<= 1;
        // 3.按该位的不同 分拨
        vector<int> part1;
        vector<int> part2;
        for (int num : nums) {
            if (num & pulse)
                part1.push_back(num);
            else
                part2.push_back(num);
        }
        // 4.对这两拨分别进行异或
        int res1 = 0, res2 = 0;
        for (int num : part1) res1 ^= num;
        for (int num : part2) res2 ^= num;
        return vector<int>{res1, res2};
    }
};