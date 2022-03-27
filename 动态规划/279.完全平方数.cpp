/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int>nums(101, 0);
        for(int i = 0; i < 101; i++){
            nums[i] = i * i;
        }
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = nums[i]; j <= n; j++){
                if(dp[j - nums[i]] != INT_MAX)dp[j] = min(dp[j], dp[j - nums[i]] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

