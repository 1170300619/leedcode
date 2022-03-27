/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k + 1, 0));
        if(n == 1 || n == 0)return 0;
        for(int i = 1; i < 2 * k + 1; i+=2){
            dp[0][i] = -prices[0];
        }
        //和买卖股票的第三个版本类似，只需要增加一层for循环即可
        //其中单数表示买入，偶数表示卖出，j = 0表示一次交易也没有进行过
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 2 * k + 1; j++){
                if(j == 0)dp[i][j] = dp[i - 1][j];
                else{
                    if(j % 2 == 1){
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                    }
                    else if(j % 2 == 0){
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                    }
                }
            }
        }
        return dp[n - 1][2 * k];
    }
};
// @lc code=end

