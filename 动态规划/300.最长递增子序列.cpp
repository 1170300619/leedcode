/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        if(n <= 1)return 1;
        vector<int> dp(n , 1);
        for(int i = 1 ; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])dp[i] = max(dp[i], dp[j] + 1);
            }
            if(dp[i] > result)result = dp[i];
        }
        return result;
    }
};
// @lc code=end

