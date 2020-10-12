// 给定一组*不含重复元素*的整数数组 nums，返回该数组所有可能的子集（幂集）。

// 说明：解集不能包含重复的子集。

// 示例:

// 输入: nums = [1,2,3]
// 输出:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/subsets
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// https://leetcode-cn.com/problems/subsets/solution/hui-su-si-xiang-tuan-mie-pai-lie-zu-he-zi-ji-wen-t/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        dfs(nums, 0, track, res);
        return res;
        
    }
    void dfs(vector<int>& nums, int begin, vector<int>& track, vector<vector<int>>& res) {
        // 不管什么情况都保存到res
        res.push_back(track);
        for (int i = begin; i < nums.size(); i++) {
            // 做选择
            track.push_back(nums[i]);
            // 回溯
            dfs(nums, i + 1, track, res);
            // 撤销选择
            track.pop_back();
        }
    }
};