import java.util.Arrays;
/*
 * @lc app=leetcode.cn id=16 lang=java
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        int index = 0;
        int t = Integer.MAX_VALUE;
        Arrays.sort(nums);
        int length  = nums.length;
        if(nums.length == 3){
            return nums[0] + nums[1] + nums[2];
        }
        if( nums[0] + nums[1] + nums[2] > target){
            return  nums[0] + nums[1] + nums[2];
        }
        if(nums[length - 1] + nums[length - 2] + nums[length- 3] < target){
            return nums[length - 1] + nums[length - 2] + nums[length- 3];
        }  
        for(int i = 0;i<nums.length - 2;i++){
            for(int j = i+ 1;j<nums.length - 1;j++){
                for(int k = j + 1;k<nums.length;k++){
                    index = Math.abs(nums[i] + nums[j] + nums[k] - target);
                    if(index < t){
                        t = index;
                        ans = nums[i] + nums[j] + nums[k];
                    }
                }
            }
        }
        return ans;
    }
}
// @lc code=end

