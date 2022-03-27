/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1 || n == 0)return 0;
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0]= 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]); //不进行操作
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); //进行买入操作
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]); //卖出
        }
        return max(dp[n - 1][0], dp[n - 1][2]);
    }
};
// @lc code=end

