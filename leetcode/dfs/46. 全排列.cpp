// # 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

// # 示例:

// # 输入: [1,2,3]
// # 输出:
// # [
// #   [1,2,3],
// #   [1,3,2],
// #   [2,1,3],
// #   [2,3,1],
// #   [3,1,2],
// #   [3,2,1]
// # ]

// # 来源：力扣（LeetCode）
// # 链接：https://leetcode-cn.com/problems/permutations
// # 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 结果数组
        vector<vector<int>> res;
        // 深度搜索的栈
        vector<int> track;
        // 访问痕迹
        vector<bool> used(nums.size(), false);
        
        dfs(nums, 0, nums.size(), track, used, res);
        return res;

    }

    void dfs(vector<int>& nums, int depth, int size, vector<int>& track, vector<bool>& used, vector<vector<int>>& res) {
        // dfs终止条件 搜到底了，保存栈结果
        if (depth == size) {
            res.push_back(track);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            // 防止重复
            if (!used[i]) {
                // 入栈搜索
                track.push_back(nums[i]);
                used[i] = true;
                // 进行dfs 此时深度+1
                dfs(nums, depth+1, size, track, used, res);
                // 弹栈 恢复 回溯
                track.pop_back();
                used[i] = false;
            }
        }
    }
};