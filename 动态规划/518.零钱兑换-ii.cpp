/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int l = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        //对于组合数，外层物品，内层背包
        for(int i = 0; i < l; i++){
            for(int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

