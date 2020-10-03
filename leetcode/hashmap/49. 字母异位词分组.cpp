// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

// 示例:

// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// 说明：

// 所有输入均为小写字母。
// 不考虑答案输出的顺序。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/group-anagrams
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1.排序
        vector<string> ss = strs;
        for (string& s : ss) {
            sort(s.begin(), s.end());
        }
        // 2.放入哈希表
        unordered_map<string, vector<int>> map;
        for (int i=0; i<ss.size(); i++) {
            if (map.find(ss[i]) == map.end()) {
                map.insert({ss[i], {i}});
            } else {
                map[ss[i]].push_back(i);
            }
        }
        // 3.输出
        vector<vector<string>> res;
        for (auto& kv : map) {
            vector<string> tmp;
            for (int i : kv.second) {
                tmp.push_back(strs[i]);
            } 
            res.push_back(tmp);
        }
        return res;
    }
};

// 简化版
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string& s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            map[t].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& kv : map) {
            res.push_back(kv.second);
        }
        return res;
    }
};