/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
    //旧版本：
// public:
//     int uniquePaths(int m, int n) {
//         int array[m][n];
//         if(m == 1 || n == 1){
//             return 1;
//         }
//         for(int i = 0;i < n;i++){
//             array[m-1][i] = 1;//最下面一行全是1
//         }
//         for(int i = 0;i < m;i++){
//             array[i][n-1] = 1;//最右边一列全是1
//         }
//         for(int i = m-2;i>=0;i--){
//             for(int j = n-2; j>=0;j--){
//                 array[i][j] = array[i][j+1] + array[i+1][j];//循环叠加，从左到右
//             }
//         }
//         return array[0][0];
//     }
public:
//dp代表到当前位置的路径条数
//最上面一行和最左边一列都是1，因为到当前位置的路都只有一条
    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[0][i] = 1;
        }
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

