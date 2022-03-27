/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        if(n == 0)return 0;
        if(n == 1)return nums[0];
        if(n == 2)return max(nums[0], nums[1]);
        if(n == 3)return max(nums[0], max(nums[1], nums[2]));

        dp1[0] = nums[0];
        dp1[1] = max(dp1[0], nums[1]);

        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);

        //两种情况

        //1.从0 到 n - 2
        for(int i = 2; i < n - 1; i++){
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }

        //2.从1到n - 1
        for(int i = 3; i < n; i++){
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }

        return max(dp1[n - 2], dp2[n -1]);
    }
};
// @lc code=end

