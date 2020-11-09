import sun.security.util.Length;

/*
 * @lc app=leetcode.cn id=31 lang=java
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
    public void nextPermutation(int[] nums) {
        int i = nums.length - 1;
        while(i > 0 && nums[i] <= nums[i - 1]){
            i--;
        }
        if(i == 0){
            reverse(nums, 0);
        }else if(i > 0){
            int j = nums.length - 1;
            while(j >= 0 && nums[j] <= nums[i - 1]){
                j--;
            }
            swap(nums, i - 1, j);
            reverse(nums, i);
        }
    }
    private void reverse(int[] nums,int start){
        int i = start, j = nums.length - 1;
        while(i < j){
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    private void swap(int[] nums, int i ,int j){
        int index = nums[j];
        nums[j] = nums[i];
        nums[i] = index;
    }
}
// @lc code=end

