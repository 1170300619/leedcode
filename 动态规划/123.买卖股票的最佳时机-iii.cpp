/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
    static bool cmp(const int& a, const int& b){
        return a > b;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)return 0;
        vector<vector<int>> dp(n, vector<int>(5, 0));
        dp[0][0] = 0; //什么也不做
        dp[0][1] = -prices[0]; //第一次买入
        dp[0][2] = 0;//第一次卖出
        dp[0][3] = -prices[0];//第二次买入，这里考虑成当天完成一次交易后再次买入
        dp[0][4] = 0;//第二次卖出
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i - 1][0]; //表示一次交也没实现过，此状态利润显然为0
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); //实现过一次买操作
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]); //实现了一次卖操作
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]); //实现了第二次买入操作
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]); //实现了第二次卖出操作
        }
        return max(dp[n - 1][2], dp[n -1][4]);
    }
};
// @lc code=end

