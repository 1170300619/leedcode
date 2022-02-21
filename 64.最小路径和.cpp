/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //原始版本写的过于复杂，边界条件太多，其实可以思考一下，从左上角到右下角的最短路径其实也是反向的最短路径
        //那么数组下标就可以从左上角开始，这样边界条件判断要少很多
        // int array[m][n];
        // memset(array,0,sizeof(array));
        // array[m-1][n-1] = grid[m-1][n-1];
        // if(m == 1 && n ==1){
        //     return array[0][0];
        // }
        // if(m == 1){
        //     for(int i = n-2;i>=0;i--){
        //         array[m-1][i] = grid[m-1][i] + array[m-1][i+1];
        //     }
        //     return array[0][0];
        // }
        // if(n == 1){
        //     for(int i = m-2;i>=0;i--){
        //         array[i][n-1] = grid[i][n-1] + array[i+1][n-1];
        //     }
        //     return array[0][0];
        // }
        // for(int i = n-2;i>=0;i--){
        //     array[m-1][i] = grid[m-1][i] + array[m-1][i+1];
        // }
        // for(int i = m-2;i>=0;i--){
        //     array[i][n-1] = grid[i][n-1] + array[i+1][n-1];
        // }
        // for(int i = m-2;i>=0;i--){
        //     for(int j = n-2;j>=0;j--){
        //         array[i][j] = grid[i][j] + min(array[i+1][j],array[i][j+1]);
        //     }
        // }
        // for(int i = 0;i < m;i++){
        //     for(int j = 0; j< n;j++){
        //         cout << array[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // return array[0][0];

        int dp[m][n];
        dp[0][0] = grid[0][0];
        for(int i = 1;i<n;i++){
            dp[0][i] = grid[0][i] +  dp[0][i-1];
        }
        for(int i = 1;i<m;i++){
            dp[i][0] = grid[i][0] +  dp[i-1][0];
        }
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

