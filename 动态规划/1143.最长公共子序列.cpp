/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    //思路很巧妙，使用dp[i][j]表示（0 , i- 1）和(0, j - 1)的最长子序列
    //这样表示起来很方便
    int longestCommonSubsequence(string text1, string text2) {
        int result = 0;
        int n = text1.size();
        int m = text2.size();
        int max_num = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i - 1] == text2[j - 1]){
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

