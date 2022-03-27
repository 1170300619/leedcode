/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        if(nums1[0] == nums2[0])dp[0][0] = 1;
        int result = 0;
        for(int j = 0; j < m; j++){
            if(nums1[0] == nums2[j]){
                dp[0][j] = 1;
                result = max(result, dp[0][j]);
            }
        }
        for(int i = 0; i < n; i++){
            if(nums1[i] == nums2[0]){
                dp[i][0] = 1;
                result = max(result, dp[i][0]);
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(nums1[i] == nums2[j]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                result = max(dp[i][j], result);
            }
        }
        return result;
    }
};
// @lc code=end

