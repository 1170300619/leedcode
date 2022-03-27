/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < strs.size(); i++){
            int zero = 0, one = 0;
            for(auto c : strs[i]){
                if(c == '0')zero++;
                else if(c == '1')one++;
            }
            //还是01背包问题，只不过换成二维，此时对于二维要使用嵌套for循环进行处理
            for(int j = m; j >= zero; j--){
                for(int k = n; k>= one; k--){
                    dp[j][k] = max(dp[j][k], dp[j - zero][k - one] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

