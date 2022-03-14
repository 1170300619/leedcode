/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
    //旧版本：写的太恐怖了，什么玩意
//1.查找最右侧一列和最下面一行是否有障碍物时，要倒序查找！
//2.对于最后的迭代累加过程，对于障碍物要单独解算
//3.结果要考虑int型能否容下，容不下使用long长整形
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         long array[m][n];
//         memset(array,0,sizeof(array));
//         bool flag = false;
//         int index = -1;
//         //判断最下侧一列是否有障碍物
//         for(int i = n-1;i >= 0;i--){
//             if(obstacleGrid[m-1][i] == 1){
//                 flag = true;
//                 index = i;
//                 break;
//             }
//         }
//         if(index == n-1)return 0;
//         if(flag){//如果有，位于障碍物右侧的都是1，障碍物本身包括左侧的都是0
//             for(int i = n-1;i>index;i--){
//                 array[m-1][i] = 1;
//             }
//             for(int i = index;i>=0;i--){
//                 array[m-1][i] = 0;
//             }
//         }else{//如果没有，则全为1
//             for(int i = 0;i<n;i++){
//                 array[m-1][i] = 1;
//             }
//         }
//         flag = false;
//         index = -1;

//         for(int i = m-1;i >=0;i--){
//             if(obstacleGrid[i][n-1] == 1){
//                 flag = true;
//                 index = i;
//                 break;
//                 //array[i][n-1] = 1;//最右边一列全是1
//             }
//         }
//         if(flag){
//             for(int i = m-1;i > index;i--){
//                 array[i][n-1] = 1;
//             }
//             for(int i = index ; i >= 0 ;i--){
//                 array[i][n-1] = 0;
//             }
//         }else{
//             for(int i = 0; i < m; i++){
//                 array[i][n-1] = 1;
//             }
//         }
        
//         for(int i = m-2;i>=0;i--){
//             for(int j = n-2; j>=0;j--){
//                 if(obstacleGrid[i][j] == 1)array[i][j] = 0;
//                 else{
//                     array[i][j] = array[i][j+1] + array[i+1][j];//循环叠加，从左到右
//                 }
//             }
//         }
//         // for(int i = 0; i < m;i++){
//         //     for(int j = 0;j < n;j++){
//         //         cout << array[i][j] << " ";
//         //     }
//         //     cout << endl;
//         // }
//         return array[0][0];
//     }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)return 0;

        vector<vector<int>> dp(m, vector(n,0));
        //下面for循环的终止条件为：遇到obstacleGrid[i][0] == 1就停止
        //这样找到第一个终止的位置，后面的都不会再赋值
        for(int i = 0; i < n && obstacleGrid[0][i] == 0; i++){
            dp[0][i] = 1;
        }
        for(int i = 0; i < m && obstacleGrid[i][0] == 0; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                else if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

