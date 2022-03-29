/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    // //DP做法
    // //实际上还是找能连成多少条不相交的线，最后判断一下线的数量是否等于s长度即可
    // bool isSubsequence(string s, string t) {
    //     int n = s.length();
    //     int m = t.length();
    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    //     for(int i = 1; i <= n; i++){
    //         for(int j = 1; j <= m; j++){
    //             if(s[i - 1] == t[j - 1]){
    //                 dp[i][j] = dp[i - 1][j - 1] + 1;
    //             }
    //             else{
    //                 dp[i][j] = max(dp[i - 1][j], dp[i][j  - 1]);
    //             }
    //         }
    //     }
    //     return (dp[n][m] == n) ? true : false;
    // }

    //双指针方法：如果s[i] == t[j]则二者同时前进一个位置
    //如果不相等，则只前进t的位置，这样贪心的找最小的t的位置使得二者相等
    //最后判断相等的数量是否等于s的长度
    bool isSubsequence(string s, string t){
        int n = s.length();
        int m = t.length();
        int s_tmp = 0, t_tmp = 0;
        int sum = 0;
        while (s_tmp < n && t_tmp < m)
        {
            if(s[s_tmp] == t[t_tmp]){
                sum++;
                s_tmp++;
                t_tmp++;
            }else{
                t_tmp++;
            }
        }
        return (sum == n) ? true : false;
    }
};
// @lc code=end

