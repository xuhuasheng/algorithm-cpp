// 给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

//  

// 示例：
// 输入：S = "a1b2"
// 输出：["a1b2", "a1B2", "A1b2", "A1B2"]

// 输入：S = "3z4"
// 输出：["3z4", "3Z4"]

// 输入：S = "12345"
// 输出：["12345"]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/letter-case-permutation
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        if (S.empty()) return res;
        string track;
        dfs(S, 0, track, res);
        return res;
    }

    void dfs(string& S, int depth, string& track, vector<string>& res) {
        if (depth == S.length()) {
            res.push_back(track);
            return;
        }
        if (isdigit(S[depth])) {
            track.push_back(S[depth]);
            dfs(S, depth+1, track, res);
            track.pop_back();
        } else if (isalpha(S[depth])) {
            track.push_back(tolower(S[depth]));
            dfs(S, depth+1, track, res);
            track.pop_back();

            track.push_back(toupper(S[depth]));
            dfs(S, depth+1, track, res);
            track.pop_back();
        }
    }
};