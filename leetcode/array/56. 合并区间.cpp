// 给出一个区间的集合，请合并所有重叠的区间。

//  

// 示例 1:

// 输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出: [[1,6],[8,10],[15,18]]
// 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2:

// 输入: intervals = [[1,4],[4,5]]
// 输出: [[1,5]]
// 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/merge-intervals
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    // 注意 sort的cmp函数 如果定义在class里则必须要加static，也可以定义在class外（则不用加static）
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            // 如果列表为空，或者当前区间与上一区间不重合，直接添加
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            // 否则的话，我们就可以与上一区间进行合并
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};