// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

// 示例 1：

// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。
// 示例 2：

// 输入: "cbbd"
// 输出: "bb"

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/longest-palindromic-substring
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n<2) return s;
        
        vector<vector<int>> dp(n, vector<int>(n,0));
        for (int i=0; i<n; i++) {
            dp[i][i] = 1;
        }
        string res;
        int max_len = 1;
        int cur_len = 0;
        int start = 0;
        for (int j=1; j<n; j++) {
            for (int i=0; i<j; i++) {
                if (s[i] == s[j]) {
                    if (j-i < 3){
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                } else {
                    dp[i][j] = 0;
                }
                if (dp[i][j]) {
                    cur_len = j-i+1;
                    if (cur_len > max_len) {
                        max_len = cur_len;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, start+max_len);
    }
};