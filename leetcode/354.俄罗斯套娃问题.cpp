// # 给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

// # 请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

// # 说明:
// # 不允许旋转信封。

// # 示例:

// # 输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
// # 输出: 3 
// # 解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。

// # 来源：力扣（LeetCode）
// # 链接：https://leetcode-cn.com/problems/russian-doll-envelopes
// # 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    //题解1：动态规划，时间复杂度O(n^2)，空间复杂度O(n)
    int maxEnvelopes_1(vector<vector<int>>& envelopes) {
        if(envelopes.empty())return 0;
        //先按w排序，若w相同，则按h由高到低排序；若w不同，则按w由小到大排序
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a,const vector<int>& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        int n=envelopes.size(),res=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(envelopes[j][1]<envelopes[i][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }

    //优化：动态规划+二分法，时间复杂度O(nlogn)，空间复杂度O(n)
    int maxEnvelopes(vector<vector<int>>& envelopes){
        if(envelopes.empty())return 0;
      //先按w排序，若w相同，则按h由高到低排序；若w不同，则按w由小到大排序
        sort(envelopes.begin(),envelopes.end(),[](const auto& a,const auto& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        vector<int> dp;
        for(auto& en:envelopes){
            int idx=lower_bound(dp.begin(),dp.end(),en[1])-dp.begin();
            if(idx>=dp.size()){
                dp.emplace_back(en[1]);
            }
            else{
                dp[idx]=en[1];
            }
        }
        return dp.size();
    }
};
