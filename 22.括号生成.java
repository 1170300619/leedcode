import java.util.ArrayList;

/*
 * @lc app=leetcode.cn id=22 lang=java
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
    List<String> res = new ArrayList<>();
    public List<String> generateParenthesis(int n) {
        if(n <= 0){
            return res;
        }
        getParenthesis("",n,n);
        return res;
    }

    private void getParenthesis(String str, int left, int right){
        if(left == 0 && right == 0){
            res.add(str);
            return;
        }

        if(left  == right){
            getParenthesis(str + '(', left - 1, right);
        }
        else if(left < right){
            if(left > 0){
                getParenthesis(str + '(', left - 1, right);
            }
            getParenthesis(str + ')', left, right - 1);
        }
    }
}
// @lc code=end

