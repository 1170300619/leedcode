import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

/*
 * @lc app=leetcode.cn id=18 lang=java
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
    List<List<Integer>> res;
    public List<List<Integer>> fourSum(int[] nums, int target) {
        res = new ArrayList<>();
        if(nums.length == 0){
            return res;
        }
        Arrays.sort(nums);
        DFS(target, nums, 0, 0, 0, new ArrayList<Integer>());
        return res;
    }

    void DFS(int target, int[] nums,int cur, int size, int sum, List<Integer> list){
        if(list.size() == 4){
            if(sum == target){
                res.add(new ArrayList<>(list));
            }
            return;
        }

        Set<Integer> set = new HashSet<>();
        for(int i = cur;i<nums.length;i++){
            //去重
            if(set.contains(nums[i])) continue;
            //剪枝： 当剩余元素个数不满足所需个数时返回
            if(nums.length - i < (4 - size)) return;
            //剪枝： 当剩余所需元素都用后续最小元素填充时还是超过了target返回
            if(i < nums.length - 1 && sum + nums[i] + (3 - size) * nums[i + 1] > target) return;
            //剪枝： 当剩余所需元素都用后续最大元素填充时还是小于target，则返回
            if(i < nums.length - 1 && sum + nums[i] + (3 - size) * nums[nums.length - 1] < target) continue;

            //回溯
            set.add(nums[i]);
            list.add(nums[i]);
            DFS(target, nums, i + 1, size + 1, sum + nums[i], list);
            list.remove(list.size() - 1);
        }
    }
}
// @lc code=end

