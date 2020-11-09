/*
 * @lc app=leetcode.cn id=33 lang=java
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
    public int search(int[] nums, int target) {
       /* int res = -1;
        for(int i = 0 ;i < nums.length; i++){
            if(nums[i] == target){
                res = i;
                return res;
            }
        }
        return res;
        */
        if(nums[0] > target && nums[nums.length -1] < target){
            return -1;
        }
        else if(nums[0] > target && nums[nums.length - 1] >= target){
            for(int i = nums.length - 1; i >= 0; i--){
                if(nums[i] == target){
                    return i;
                }
            }
        }
        else if(nums[0] == target){
            return 0;
        }
        else if(nums[0] < target){
            for(int i = 0;i < nums.length; i++){
                if(nums[i] == target){
                    return i;
                }
            }
        }
        return -1;
        
    }
}
// @lc code=end

