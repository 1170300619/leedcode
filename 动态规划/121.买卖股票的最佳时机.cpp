/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)return 0;
        vector<vector<int>> dp(n, vector<int>(2,0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < n; i++){
            //这里要注意不是dp[i - 1][1] - prices[i]，因为要保证只买入卖出一次
            //那么今天持有股票剩下的最多现金就是dp[i - 1][0]和今天第一次买入-prices[i]
            dp[i][0] = max(-prices[i], dp[i - 1][0]); 
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
        }
        return dp[n - 1][1];
    }
};
// @lc code=end

