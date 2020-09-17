import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode.cn id=15 lang=java
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();

        if(nums == null || nums.length < 3){
            return ans;
        }
        
        Arrays.sort(nums);

        if(nums[0]> 0){
            return ans;
        }
        int start,end = 0;
        for(int i = 0;i<nums.length - 2;i++){
            if(i > 0 && (nums[i] == nums[i - 1])){
                continue;
            }
            start = i + 1;
            end = nums.length -1;
            while(start < end){
                if(nums[i] + nums[start] + nums[end] == 0){
                    ans.add(new ArrayList<>(Arrays.asList(nums[i],nums[start],nums[end])));
                    start++;
                    end--;
                    while(start < end && nums[start] == nums[start - 1]){
                        start++;
                    }
                    while(start < end && nums[end] == nums[end + 1]){
                        end--;
                    }
                }else if(nums[i] + nums[start] + nums[end] < 0){
                    start++;
                }else if(nums[i] + nums[start] + nums[end] > 0){
                    end--;
                }
            }
        }
        return ans;
    }
}
// @lc code=end

