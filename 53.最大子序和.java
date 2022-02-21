/*
 * @lc app=leetcode.cn id=53 lang=java
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) {
        int pre = 0, maxAns = nums[0];
        for (int x : nums) {
            pre = Math.max(pre + x, x);//对于连续性的字串，比较的是当前元素以及当前元素加上之前的值的大小
            maxAns = Math.max(maxAns, pre);
        }
        return maxAns;
    }
}
// @lc code=end

