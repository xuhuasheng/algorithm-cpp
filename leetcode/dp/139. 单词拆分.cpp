// 给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

// 说明：

// 拆分时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。
// 示例 1：

// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
// 示例 2：

// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//      注意你可以重复使用字典中的单词。
// 示例 3：

// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出: false

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/word-break
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// https://leetcode-cn.com/problems/word-break/solution/dong-tai-gui-hua-ji-yi-hua-hui-su-zhu-xing-jie-shi/
// # 时间复杂度：O(n^{2})
// # 空间复杂度：O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 放入set
        unordered_set<string> dict;
        for (string word : wordDict) {
            dict.insert(word);
        }
        // dp
        int n = s.size();
        // 1.定义dp数组：dp[i] 表示 s 的前 i 位是否可以用 wordDict 中的单词表示
        vector<bool> dp((n+1), false);
        // 2.basecase：空字符可以被表示
        dp[0] = true;
        // 3.递推
        // 遍历字符串的所有子串，遍历开始索引 i，遍历区间 [0,n)
        for (int i=0; i<n; i++) {
            // 遍历结束索引 j，遍历区间 [i+1,n+1)
            for (int j=i+1; j<=n; j++) {
                // dp[i]=True 说明 s 的前 i 位可以用 wordDictwordDict 表示
                // 并且 s[i:j] 出现在 wordDictwordDict 中，说明 s 的前 j 位可以表示
                if (dp[i] && dict.count(s.substr(i, j-i))) {
                    dp[j] = true;
                }
            }
        }
        return dp[n];
    }
};