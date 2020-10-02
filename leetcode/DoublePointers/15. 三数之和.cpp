// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

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

// https://leetcode-cn.com/problems/3sum/solution/pai-xu-shuang-zhi-zhen-zhu-xing-jie-shi-python3-by/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n<3) return {};

        // 排序-剪枝前提
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i=0; i<n; i++) {
            // 大剪枝
            if (nums[i] > 0) break;
            // 小剪枝
            if (i > 0 && nums[i] == nums[i-1]) continue;
            // 双指针
            int left = i+1;
            int right = n-1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    // 避免重复
                    while (left < right && nums[left] == nums[left+1]) left ++;
                    while (left < right && nums[right] == nums[right-1]) right --;
                    // 更新指针
                    left ++;
                    right --;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left ++;
                } else {
                    right --;
                }
            }
        }
        return res;
    }
};

// dfs超时
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> track;
        vector<vector<int>> res;
        // 排序-剪枝前提
        sort(nums.begin(), nums.end());
        dfs(nums, 0, 0, track, res);
        return res;
    }

    void dfs(vector<int>& nums, int begin, int target, vector<int>& track, vector<vector<int>>& res) {
        if (track.size() == 3) {
            if (target == 0) {
                res.push_back(track);
                // return; 隐性返回
            }
            // return; 隐性返回
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

