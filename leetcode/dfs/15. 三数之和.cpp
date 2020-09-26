// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

//  

// 示例：

// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/3sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// dfs会超时
// 应该用双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> track;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, 0, track, res);
        return res;
    }

    void dfs(vector<int>& nums, int begin, int target, vector<int>& track, vector<vector<int>>& res) {
        // 一级条件：深度 若不满足则继续dfs
        if (track.size() == 3) {    
            // 二级条件：和 如果满足条件则存储并返回上一层，如果不满足则返回上一层
            if (target == 0) {
                res.push_back(track);
                return;
            }
        }
        else {
            for (int i=begin; i<nums.size(); i++) {
                // 大剪枝
                if (target - nums[i] < 0) break;
                // 小剪枝
                if (i > begin && nums[i-1] == nums[i]) continue;
                track.push_back(nums[i]);
                dfs(nums, i+1, target-nums[i], track, res);
                track.pop_back();
            }
        }
    }
};