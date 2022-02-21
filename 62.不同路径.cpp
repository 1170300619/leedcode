/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        int array[m][n];
        if(m == 1 || n == 1){
            return 1;
        }
        for(int i = 0;i < n;i++){
            array[m-1][i] = 1;//最下面一行全是1
        }
        for(int i = 0;i < m;i++){
            array[i][n-1] = 1;//最右边一列全是1
        }
        for(int i = m-2;i>=0;i--){
            for(int j = n-2; j>=0;j--){
                array[i][j] = array[i][j+1] + array[i+1][j];//循环叠加，从左到右
            }
        }
        return array[0][0];
    }
};
// @lc code=end

