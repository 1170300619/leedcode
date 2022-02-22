/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)return 0;
        int pri = 0;
        int curpri = 0;
        for(int i = 0; i < prices.size() - 1; i++)
        {
            if(prices[i + 1] - prices[i] > 0){
                curpri = prices[i + 1] - prices[i];
            }
            pri += curpri;
            curpri = 0;
        }
        return pri;
    }
};
// @lc code=end

