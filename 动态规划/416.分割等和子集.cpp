/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum % 2 == 1)return false;
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for(int i = 0; i < n; i++){
            for(int j = target; j >= nums[i]; j--){
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if(dp[target] - target != 0)return false;
        return true;
    }
};
// @lc code=end

