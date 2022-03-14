/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
    //思路挺难想的
    //dp[i]的值由子树决定，从1到i进行遍历
    //每次计算左子树和右子树的dp值，且左子树节点个数一定是j - 1
    //例如以3为根节点，则左侧节点分别为1和2
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

