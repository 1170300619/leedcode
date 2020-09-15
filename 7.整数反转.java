/*
 * @lc app=leetcode.cn id=7 lang=java
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
    public int reverse(int x) {
        int ans = 0,index = 0;
        while(x != 0){
            //利用三个变量计算反转的数字
            index = x % 10;
            x /= 10;
            //如果是正数，则判断是否大于Integer.MAX_VALUE / 10，如果大于则return 0
            //如果正好相等，则最后一位不能大于7
            if(ans > (Integer.MAX_VALUE / 10) || (ans == (Integer.MAX_VALUE / 10)&& index > 7)){
                return 0;
            }
            //如果是负数，则判断是否小于Integer.MIN_VALUE / 10，如果小于则return 0
            //如果正好相等，则最后一位不能小于-8
            if(ans < (Integer.MIN_VALUE / 10) || (ans == (Integer.MIN_VALUE / 10) && index < -8)){
                return 0;
            }
            ans = ans * 10 + index;
        }
        return ans;
    }
}
// @lc code=end

