/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;//分拆2，最大的结果就是1
        for(int i = 3;i <= n; i++){//所以i从3开始
            //对于i而言，将其从1到i - 1进行分拆，迭代过程中记录最大值
            for(int j = 1; j < i; j++){
                //j * (i - j)是指分拆出来j之后不再进行分拆
                //j * dp[i - j]是指分拆出来j后，继续分拆i - j
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};
// @lc code=end

