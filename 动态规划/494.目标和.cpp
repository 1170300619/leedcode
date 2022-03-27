/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(abs(target) > sum)return 0;
        if((abs(target) + sum) % 2 == 1)return 0;
        int bag = (abs(target) + sum) / 2;
        vector<int> dp(bag + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = bag; j >= nums[i]; j--){
                //在求装满背包有几种方法的情况下，递推公式一般为：
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bag];
    }
};
// @lc code=end

