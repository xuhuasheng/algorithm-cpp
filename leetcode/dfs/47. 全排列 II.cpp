// 给定一个*可包含重复数字*的序列，返回所有不重复的全排列。

// 示例:

// 输入: [1,1,2]
// 输出:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/permutations-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// https://leetcode-cn.com/problems/permutations-ii/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liwe-2/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        vector<bool> used(nums.size(), false);
        // 先排序 这很关键=============
        sort(nums.begin(), nums.end());
        // ===========================
        dfs(nums, 0, nums.size(), track, used, res);
        return res;
    }

    void dfs(vector<int>& nums, int depth, int size, vector<int>& track, vector<bool>& used, vector<vector<int>>& res) {
        if (depth == size) {
            res.push_back(track);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            if (!used[i]) {
                // 剪枝 (题目特征：候选序列可包含重复数字)================
                if (i>0 && nums[i] == nums[i-1] && used[i-1] == false) {
                    continue;
                }
                // ====================================================
                track.push_back(nums[i]);
                used[i] = true;
                dfs(nums, depth+1, size, track, used, res);
                track.pop_back();
                used[i] = false;
            }
        }
    }
};