/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        if(n == 1)return 0;
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < n; i++){
            //这个版本就是可以多次买卖股票
            //所以今天持有股票的最大现金就是dp[i - 1][0]和dp[i - 1][1]  prices[i]取最大
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[n - 1][1];
    }
};
// @lc code=end

