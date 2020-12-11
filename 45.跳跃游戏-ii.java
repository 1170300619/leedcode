/*
 * @lc app=leetcode.cn id=45 lang=java
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
    public int jump(int[] nums) {
        int time = 0;
        int index = 0;
        int ans = 0;
        if(nums.length == 1){
            return 0;
        }
        while(nums[index] + index < nums.length - 1){
            int end = nums[index] + index;
            for(int i = index + 1; i <= end; i++){
                if(nums[i] + i >= ans){ //nums[i] + i 很关键，即比较从当前的位置出发谁能达到的最远距离，并且>=的情况也要保留
                    index = i;
                    ans = nums[i] + i;
                }else{
                    continue;
                }
            }
            time++;
            ans = 0;
        } 
        return ++time;
    }
}
// @lc code=end

