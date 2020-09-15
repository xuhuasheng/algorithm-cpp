// # 给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。

// # 示例 1:
// # 输入:
// # "bbbab"
// # 输出:
// # 4
// # 一个可能的最长回文子序列为 "bbbb"。

// # 示例 2:
// # 输入:
// # "cbbd"
// # 输出:
// # 2
// # 一个可能的最长回文子序列为 "bb"。

// # 提示：
// # 1 <= s.length <= 1000
// # s 只包含小写英文字母

// # 来源：力扣（LeetCode）
// # 链接：https://leetcode-cn.com/problems/longest-palindromic-subsequence
// # 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// # 题解  https://leetcode-cn.com/problems/longest-palindromic-subsequence/solution/zi-xu-lie-wen-ti-tong-yong-si-lu-zui-chang-hui-wen/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // 二维dp数组
        vector<vector<int>> dp(n, vector<int>(n,0));
        // 对角线初始化 base case
        for (int i=0; i<n; i++) {
            dp[i][i] = 1;
        }
        // 填表 注意状态转移的依赖关系 和 填表顺序
        for (int i=n-2; i>=0; i--) {
            for (int j=i+1; j<n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};