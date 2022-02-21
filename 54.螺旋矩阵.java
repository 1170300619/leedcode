import java.util.ArrayList;
import java.util.List;

import javax.swing.border.Border;

/*
 * @lc app=leetcode.cn id=54 lang=java
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        List<Integer> result = new ArrayList<>();
        if(matrix.length == 0 || matrix == null)return result;

        int left = 0;
        int right = n - 1;
        int up = 0;
        int bottom = m - 1;
        int num = m * n;
        while(num >= 1){
            for(int i = left;i <= right && num >= 1;i++){
                result.add(matrix[up][i]);
                num--;
            }
            up++;
            for(int i = up; i <= bottom && num >= 1; i++){
                result.add(matrix[i][right]);
                num--;
            }
            right--;
            for(int i = right; i >= left && num >= 1; i--){
                result.add(matrix[bottom][i]);
                num--;
            }
            bottom--;
            for(int i = bottom; i >= up && num >= 1;i--){
                result.add(matrix[i][left]);
                num--;
            }
            left++;
        }
        return result;
    }
}
// @lc code=end

