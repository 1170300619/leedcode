/*
 * @lc app=leetcode.cn id=8 lang=java
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
    public int myAtoi(String str) {
        if(str == null || str.length() == 0)return 0;

        StringBuilder ans = new StringBuilder();
        int index = 0;
        for(index = 0;index<str.length();index++){
            if(str.charAt(index) == ' ' && ans.length() == 0){
                continue;
            }else if((str.charAt(index) == '+' || str.charAt(index) == '-') && ans.length() == 0){
                ans.append(str.charAt(index));
            }else if(str.charAt(index) >= 48 && str.charAt(index) <= 57){
                ans.append(str.charAt(index));
            }else{
                break;
            }
        }

        if(ans.length() == 0){
            return 0;
        }

        int flag = 0;
        int result = 0;
        int temp = 0;

        if(ans.charAt(0) == '+'){
            temp = 1;
        }else if(ans.charAt(0) == '-'){
            flag = 1;
            temp = 1;
        }
        
        while(temp < ans.length()){
            int k = ans.charAt(temp) - '0';
            if(flag == 0 && (result > Integer.MAX_VALUE / 10 || (result == Integer.MAX_VALUE /10 && k > 7))){
                return Integer.MAX_VALUE;
            }
            if(flag == 1 && (-result < Integer.MIN_VALUE / 10 || (-result == Integer.MIN_VALUE / 10 && -k < -8))){
                return Integer.MIN_VALUE;
            }
            else{
                result = result * 10 + k;
                temp++;
            }   
        }
        if(flag == 1){
            return -result;
        }
        return result;
    }   
}
// @lc code=end

