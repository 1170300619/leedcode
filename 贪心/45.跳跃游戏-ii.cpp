/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)return 0;
        int ans = 0;
        int curDis = 0, nextDis = 0;
        for(int i = 0; i < nums.size(); i++){
            nextDis = max(i + nums[i], nextDis);
            if(nextDis >= nums.size() - 1)return ans + 1;
            if(i == curDis){
                ans++;
                curDis = nextDis;
            }
        }
        return ans;
    }
};
// @lc code=end

