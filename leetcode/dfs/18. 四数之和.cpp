// # 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

// # 注意：

// # 答案中不可以包含重复的四元组。

// # 示例：

// # 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

// # 满足要求的四元组集合为：
// # [
// #   [-1,  0, 0, 1],
// #   [-2, -1, 1, 2],
// #   [-2,  0, 0, 2]
// # ]

// # 来源：力扣（LeetCode）
// # 链接：https://leetcode-cn.com/problems/4sum
// # 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// # 此题用dfs超时
// # 考虑双指针
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> track;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, target, track, res);
        return res;
    }

    void dfs(vector<int>& nums, int begin, int target, vector<int>& track, vector<vector<int>>& res) {
        if (track.size() == 4) {
            if (target == 0) {
                res.push_back(track);
                return;
            }
        }
        else {
            for (int i=begin; i<nums.size(); i++) {
                if (target >=0 && target-nums[i] < 0) break;
                if (i > begin && nums[i-1] == nums[i]) continue;
                track.push_back(nums[i]);
                dfs(nums, i+1, target-nums[i], track, res);
                track.pop_back();
            }
        }
    }
};

// 双指针
// 时间复杂度：O(n^3)，排序的时间复杂度是 O(nlogn)，枚举四元组的时间复杂度是 O(n^3)
// 因此总时间复杂度为 O(n^3+nlogn)
// 空间复杂度：O(logn)，空间复杂度主要取决于排序额外使用的空间。
// 此外排序修改了输入数组 nums，实际情况中不一定允许，
// 因此也可以看成使用了一个额外的数组存储了数组 nums 的副本并排序，空间复杂度为 O(n)。

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 4) return res;
        // 排序-前提
        sort(nums.begin(), nums.end());

        int a, b, c, d;
        // 外循环
        for (a=0; a<=n-4; a++) {
            if (a>0 && nums[a] == nums[a-1]) continue; //确保nums[a] 改变了
            // 内循环
            for (b=a+1; b<=n-3; b++) {
                if (b>a+1 && nums[b] == nums[b-1]) continue; //确保nums[b] 改变了
                c = b+1;
                d = n-1;
                // 双指针
                while (c < d) {
                    if (nums[a]+nums[b]+nums[c]+nums[d] == target) {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while (c<d && nums[c] == nums[c+1]) c++;    //确保nums[c] 改变了
                        while (c<d && nums[d] == nums[d-1]) d--;    //确保nums[d] 改变了
                        c++;
                        d--;
                    } else if (nums[a]+nums[b]+nums[c]+nums[d] < target) {
                        c++;
                    } else if (nums[a]+nums[b]+nums[c]+nums[d] > target) {
                        d--;
                    }
                }
            }
        }
        return res;
    }
};