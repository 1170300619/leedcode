/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        int dp[size + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < size; i++){
            dp[i] = min(dp[i - 2] + cost[i], dp[i - 1] + cost[i]);
        }
        //最后还要上一层台阶，此时楼顶size层的上法有两种：
        //从size - 1层花费cost[size - 1]上去
        //从size  2层花费cost[size - 2]上去
        dp[size] = min(dp[size - 1], dp[size - 2]);
        return dp[size];
    }
};
// @lc code=end

