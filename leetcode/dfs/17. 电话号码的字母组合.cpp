// # 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

// # 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

// # d = {2:"abc", 3:"def", 4:"ghi", 5:"jkl", 6:"mno", 7:"pqrs", 8:"tuv", 9:"wxyz"}
// # 示例:

// # 输入："23"
// # 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// # 说明:
// # 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

// # 来源：力扣（LeetCode）
// # 链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
// # 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// # https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/dian-hua-hao-ma-de-zi-mu-zu-he-by-leetcode-solutio/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string track;
        dfs(phoneMap, digits, 0, track, res);
        return res;
    }


    void dfs(const unordered_map<char, string>& phoneMap, const string& digits, int index, string& track, vector<string>& res) {
        if (index == digits.length()) {
            res.push_back(track);
            return;
        }

        char digit = digits[index];
        const string& letters = phoneMap.at(digit);
        for (const char& letter: letters) {
            track.push_back(letter);
            dfs(phoneMap, digits, index + 1, track, res);
            track.pop_back();
        }
    }

};