import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=36 lang=java
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
    public boolean isValidSudoku(char[][] board) {
        /*Set<Integer> set = new HashSet<>();
        int index = 0;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] <= '9' && board[i][j] >=  '0'){
                    index = (int)(board[i][j] - '0');
                    if(set.contains(index)){
                        return false;
                    }else {
                        set.add(index);
                    }
                }
            }
            set.clear();
        }
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[j][i] <= '9' && board[j][i] >=  '0'){
                    index = (int)(board[j][i] - '0');
                    if(set.contains(index)){
                        return false;
                    }else {
                        set.add(index);
                    }
                }
            }
            set.clear();
        }

        //9个小格
        for(int i = 0; i < 3 ;i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] <= '9' && board[i][j] >=  '0'){
                    index = (int)(board[i][j] - '0');
                    if(set.contains(index)){
                        return false;
                    }else {
                        set.add(index);
                    }
                }
            }
        }
        set.clear();
        for(int i = 0; i < 3; i++){
            for(int j = 3; j < 6; j++){
                if(board[i][j] <= '9' && board[i][j] >=  '0'){
                    index = (int)(board[i][j] - '0');
                    if(set.contains(index)){
                        return false;
                    }else {
                        set.add(index);
                    }
                }
            }
        }
        set.clear();
        for(int i = 0; i < 3; i++){
            for(int j = 6; j < 9; j++){
                if(board[i][j] <= '9' && board[i][j] >=  '0'){
                    index = (int)(board[i][j] - '0');
                    if(set.contains(index)){
                        return false;
                    }else {
                        set.add(index);
                    }
                }
            }
        }
        set.clear();
        for(int i = 3; i < 6; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] <= '9' && board[i][j] >=  '0'){
                    index = (int)(board[i][j] - '0');
                    if(set.contains(index)){
                        return false;
                    }else {
                        set.add(index);
                    }
                }
            }
        }
        set.clear();
        for(int i = 3; i < 6; i++){
            for(int j = 3; j < 6; j++){
                if(board[i][j] <= '9' && board[i][j] >=  '0'){
                    index = (int)(board[i][j] - '0');
                    if(set.contains(index)){
                        return false;
                    }else {
                        set.add(index);
                    }
                }
            }
        }
        set.clear();
        for(int i = 3; i < 6; i++){
            for(int j = 6; j < 9; j++){
                if(board[i][j] <= '9' && board[i][j] >=  '0'){
                    index = (int)(board[i][j] - '0');
                    if(set.contains(index)){
                        return false;
                    }else {
                        set.add(index);
                    }
                }
            }
        }
        set.clear();
        for(int i = 6; i < 9; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] <= '9' && board[i][j] >=  '0'){
                    index = (int)(board[i][j] - '0');
                    if(set.contains(index)){
                        return false;
                    }else {
                        set.add(index);
                    }
                }
            }
        }
        set.clear();
        for(int i = 6; i < 9; i++){
            for(int j = 3; j < 6; j++){
                if(board[i][j] <= '9' && board[i][j] >=  '0'){
                    index = (int)(board[i][j] - '0');
                    if(set.contains(index)){
                        return false;
                    }else {
                        set.add(index);
                    }
                }
            }
        }
        set.clear();
        for(int i = 6; i < 9; i++){
            for(int j = 6; j < 9; j++){
                if(board[i][j] <= '9' && board[i][j] >=  '0'){
                    index = (int)(board[i][j] - '0');
                    if(set.contains(index)){
                        return false;
                    }else {
                        set.add(index);
                    }
                }
            }
        }
        set.clear();
        return true;*/
        int[][] rows = new int[9][9];
        int[][] col = new int[9][9];
        int[][] sbox = new int[9][9];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j]!='.'){
                    int num = board[i][j] - '1';
                    int index_box = (i/3)*3+j/3;
                    if (rows[i][num]==1) { return false;}
                    else { rows[i][num]=1; }
                    if (col[j][num]==1) { return false;}
                    else { col[j][num]=1; }
                    if (sbox[index_box][num]==1)  { return false;}
                    else { sbox[index_box][num]=1; }
                }
            }
        }
        return true;
    }
}
// @lc code=end

