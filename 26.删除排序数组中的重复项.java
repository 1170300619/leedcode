import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=26 lang=java
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
    public int removeDuplicates(int[] nums) {
        /*Set<Integer> set = new HashSet<>();
        for(int i = 0;i < nums.length;i++){
            if(set.contains(nums[i])){
                continue;
            }
            set.add(nums[i]);
        }
        List<Integer> list = new ArrayList<>(set);
        list.sort(Comparator.naturalOrder());
        for(int i =0;i<set.size();i++){
            nums[i] = list.get(i);
        }
        return set.size();
        */
        int index = 0;
        for(int i = 0;i<nums.length - 1;i++){
            if(nums[i + 1] == nums[i]){
                continue;
            }
            nums[++index] = nums[i+1];
        }
        return ++index;
    }
}
// @lc code=end

