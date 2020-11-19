// 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
//
// 请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
//
// 你可以假设 nums1 和 nums2 不会同时为空。
//
//  
//
// 示例 1:
//
// nums1 = [1, 3]
// nums2 = [2]
//
// 则中位数是 2.0
// 示例 2:
//
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// 则中位数是 (2 + 3)/2 = 2.5
//
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 法1：暴力合并取中位数
// space:    o(m+n)
// time:     o(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = (nums1.size() + nums2.size() + 1)/2;
        vector<int> merge;
        while (nums1.size() && nums2.size()) {
            if (nums1.back() > nums2.back()) {
                merge.push_back(nums1.back());
                nums1.pop_back();
            } else {
                merge.push_back(nums2.back());
                nums2.pop_back();
            }
        }
        while (nums1.size()) {
            merge.push_back(nums1.back());
            nums1.pop_back();
        }
        while (nums2.size()) {
            merge.push_back(nums2.back());
            nums2.pop_back();
        }
        if ((merge.size() & 1) == 0) {
            return (double)(merge[m-1]+merge[m])/2;
        } else {
            return (double)merge[m-1];
        }
    }
};

// 法2：二分法：
// time:   o(log(min(m,n)))
// space:  o(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // 令nums1是较短的数组(转化问题)
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        // 两个数组的中位数分割线的左侧总数
        int totalLeft = (m+n+1) / 2;

        // nums1的分割线的二分法的左右边界
        int iLeft = 0;
        int iRight = m;

        // 二分法
        while (iLeft < iRight) {
            int i = iLeft + (iRight-iLeft)/ 2;
            int j = totalLeft - i;
            if (nums1[i] < nums2[j-1]) {
                iLeft = i+1;
            } else {
                iRight = i;
            }
        }

        int i = iLeft;
        int j = totalLeft - i;
        int nums1LeftMax = (i==0) ? INT_MIN : nums1[i-1];
        int nums1RightMin = (i==m) ? INT_MAX : nums1[i];
        int nums2LeftMax = (j==0) ? INT_MIN : nums2[j-1];
        int nums2RightMin = (j==n) ? INT_MAX : nums2[j];

        // 判断奇偶
        if ((m+n)&1 == 1) {
            return (double) max(nums1LeftMax, nums2LeftMax);
        } else {
            return (double) (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2;
        }
    }
};


