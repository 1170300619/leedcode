/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
//上一层有一种方法，上两层有两种方法，那么定义up_one和up_two分别为1和2
//dp数组保存的是当前楼层的总方法数，那么第一层楼有一种，第二层楼有两种
//此时能上到第三层的只有第一层和第二层，那么上第三层的方法就是上第一层方法加上第二层方法
//也就是说，假如已经上到了第n层，那么只有两种可能：最后一步上了一层和上了两层，
//所以dp[n] = dp[n - 1] + dp[n - 2]

    int climbStairs(int n) {
        if(n <= 1)return n;
        int dp[n + 1];
        int up_one = 1;
        int up_two = 2;
        dp[1] = up_one;
        dp[2] = up_two;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};
// @lc code=end

