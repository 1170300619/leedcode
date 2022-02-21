/*
 * @lc app=leetcode.cn id=55 lang=java
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length == 1){
            return true;
        }
        int index = 0;
        int max = -1;
        if(nums[index] + index >= nums.length - 1){
            return true;
        }
        int t = 0;
        while(nums[index] + index < nums.length - 1){
            for(int i = index + 1; i <= nums[index] + index; i++){
                if(nums[i] + i >= max && nums[i] + i < nums.length - 1){
                    max = nums[i] + i;
                    t = i;
                }
                else if(nums[i] + i >= nums.length - 1){
                    return true;
                }
            }
            index = t;
            if(nums[index] == 0){
                break;
            }
        } 
        return false;
    }
}
// @lc code=end

