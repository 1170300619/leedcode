/*
 * @lc app=leetcode.cn id=48 lang=java
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
    public void rotate(int[][] matrix) {
        int col = matrix.length;
        int index = 0;
        for(int i = 0 ;i < col; i++){
            for(int j = i; j < col; j++){
                index = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = index;
            }
        }
        for(int i = 0; i < col; i++){
            for(int j = 0; j < (col / 2); j++){
                index = matrix[i][j];
                matrix[i][j] = matrix[i][col - 1 - j];
                matrix[i][col - 1 - j] = index;
            }
        }
    }
}
// @lc code=end

