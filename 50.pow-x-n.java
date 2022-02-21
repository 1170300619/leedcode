/*
 * @lc app=leetcode.cn id=50 lang=java
 *
 * [50] Pow(x, n)
 */

// @lc code=start

// 快速幂方法 递归方法
class Solution {
    public double myPow(double x, int n) {
        int index = n;
        return n >= 0 ? quickMul(x, n) : 1 / quickMul(x, -n);
    }

    private double quickMul(double x, int n){
        if(n == 0){
            return 1;
        }
        double y = quickMul(x, n / 2);
        return n % 2 == 0 ? y * y : y * y * x;
    }
}
// @lc code=end

