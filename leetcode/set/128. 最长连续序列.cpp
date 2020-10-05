// 给定一个未排序的整数数组，找出最长连续序列的长度。

// 要求算法的时间复杂度为 O(n)。

// 示例:

// 输入: [100, 4, 200, 1, 3, 2]
// 输出: 4
// 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// Time: O(n) Space: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 放入集合去重
        unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        } 

        int maxLen = 0;
        for (const int& num : st) {
            // 如果不跟前面的连续
            if (!st.count(num-1)) {
                int curNum = num;
                int curLen = 1;
                // 一直查看是否跟后面的连续
                while (st.count(++curNum)) {
                    curLen++;
                }
                // 维护max值
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
    }
};