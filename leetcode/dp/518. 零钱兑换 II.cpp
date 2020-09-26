// 给定不同面额的硬币和一个总金额。
// 写出函数来计算可以凑成总金额的硬币组合数。
// 假设每一种面额的硬币有无限个。 

// 示例 1:
// 输入: amount = 5, coins = [1, 2, 5]
// 输出: 4
// 解释: 有四种方式可以凑成总金额:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1

// 示例 2:
// 输入: amount = 3, coins = [2]
// 输出: 0
// 解释: 只用面额2的硬币不能凑成总金额3。

// 示例 3:
// 输入: amount = 10, coins = [10] 
// 输出: 1

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/coin-change-2
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        // 遍历硬币
        for (int& coin : coins) {
            // 遍历容量
            for (int j = 1; j <= amount; j++) {
                // 如果能装下
                if (j >= coin) {
                    dp[j] += dp[j - coin];
                }
            }
        }
        return dp[amount];
    }
};

// dfs超时
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> track;
        vector<vector<int>> res;
        sort(coins.begin(), coins.end());
        dfs(coins, amount, 0, track, res);
        return res.size();
    }
    void dfs(vector<int>& coins, int target, int begin, vector<int>& track, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(track);
            return;
        }
        for (int i = begin; i < coins.size(); i++) {
            if (target - coins[i] < 0) {
                break;
            }

            track.push_back(coins[i]);
            dfs(coins, target - coins[i], i, track, res);
            track.pop_back();
        }
    }
};


