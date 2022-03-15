/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int weight = 0;
        for(int i = 0; i < stones.size(); i++){
            weight += stones[i];
        }
        int target = weight / 2;
        vector<int> dp(target + 1, 0);

        for(int i = 0; i < stones.size(); i++){
            for(int j = target; j >= stones[i]; j--){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return (weight - 2 * dp[target]);
    }
};
// @lc code=end

