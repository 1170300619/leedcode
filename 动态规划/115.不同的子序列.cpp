/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(); 
        int m = t.length();
        //用int可能溢出，使用uint64_t来代替
        vector<vector<uint64_t>> dp(n + 1, vector<uint64_t>(m + 1, 0));
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }   
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

