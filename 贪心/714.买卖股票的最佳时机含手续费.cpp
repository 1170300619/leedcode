/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        //dp[i][0] 第i天持有股票所剩的最多现金
        //dp[i][1] 第i天持有的最多现金
        vector<vector<int>> dp (n,vector<int> (2,0));
        dp[0][0] -= prices[0];
        for(int i = 1; i < n; ++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
            cout << dp[i][0] << " " << dp[i][1] << endl;
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
// @lc code=end

