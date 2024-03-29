/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
class Solution {
public:
    //找左上角区域的最大值，就用这个方法
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n == 0 || m == 0)return 0;
        vector<vector<int>> dp(n + 1, vector<int>(m  + 1 , 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(nums1[i - 1] == nums2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];                                  
    }
};
// @lc code=end

