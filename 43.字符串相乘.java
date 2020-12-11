/*
 * @lc app=leetcode.cn id=43 lang=java
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
    public String multiply(String num1, String num2) {
        int time = num2.length();
        if(num1.equals("0") || num2.equals("0")){
            return "0";
        }
        int [] res = new int [num1.length() + num2.length()];
        for(int i = num1.length() - 1; i >= 0; i--){
            for(int j = num2.length() - 1; j >= 0; j--){
                int index = res[i + j + 1] + (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                res[i + j + 1] = index % 10;
                res[i + j] += index / 10;
            }
        }

        StringBuilder result = new StringBuilder();
        for(int i = 0; i < res.length; i++){
            if(i == 0 && res[i] == 0){
                continue;
            }
            result.append(res[i]);
        }
        return result.toString();
    }
}
// @lc co\de=end

