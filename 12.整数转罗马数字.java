/*
 * @lc app=leetcode.cn id=12 lang=java
 *
 * [12] 整数转罗马数字
 */

// 正常做法：将每一位都转化成单独的数字处理
// @lc code=start
/*
class Solution {
    public String intToRoman(int num) {
        String [] thousands = {"","M","MM","MMM"};
        String [] hundreds = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        String [] tens = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        String [] ones = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        
        return thousands[num / 1000] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    }
}
*/

//贪心做法：罗马数字的表示法是从左侧开始选择最大的数字，然后减去这个数字，循环往复

class Solution {
    public String intToRoman(int num) {
        int [] value = {1,4,5,9,10,40,50,90,100,400,500,900,1000,4000};
        String [] Roman = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M",""};
        
        String ans = "";
        int index = 0;
        
        while(index < value.length && num != 0){
            if(num >= value[index]){
                index++;
                continue;
            }else{
                num -= value[index - 1];
                ans += Roman[index - 1];
                index = 0;
            }
        }
        return ans;
    }
}
// @lc code=end

