import sun.awt.image.ImageAccessException;

/*
 * @lc app=leetcode.cn id=34 lang=java
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
    public int[] searchRange(int[] nums, int target) {
        /*int index;
        int[] res = new int[] {-1,-1};
        if(nums.length == 0 || nums == null || nums[0] > target || nums[nums.length - 1] < target){
            return res;
        }
        for(index = 0; index < nums.length; index++){
            if(nums[index] == target){
                res[0] = index;
                break;
            }else{
                continue;
            }
        }
        for(index = nums.length - 1; index >= 0; index--){
            if(nums[index] == target){
                res[1] = index;
                break;
            }else{
                continue;
            }
        }
        return res;
        */
        int[] res = {-1,-1};

        int leftIndex = extremeIndertioonIndex(nums, target, true);

        if(leftIndex == nums.length || nums[leftIndex] != target){
            return res;
        }
        
        res[0] = leftIndex;
        res[1] = extremeIndertioonIndex(nums, target, false) - 1;

        return res;
    }

    //boolean: left(这个参数表示：如果为true，则递归搜索左区间，否则递归搜索右区间)
    private int extremeIndertioonIndex(int[] nums, int target, boolean left){
        int low = 0;
        int high = nums.length;
        
        while(low < high){
            int mid = (low + high) / 2;
            if(nums[mid] > target || (left && target == nums[mid])){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
}
// @lc code=end

