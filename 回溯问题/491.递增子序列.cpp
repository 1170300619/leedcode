/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(const vector<int>& nums, int startIndex){
        if(path.size() >= 2){
            result.push_back(path);
        }
        for(int i = startIndex; i < nums.size(); i++){
           if(i != startIndex && !isRepeat(nums, startIndex, i))continue;
           if(startIndex == 0 || nums[i] >= path.back()){
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
           }
        }   
    }
    //判断从[startIndex, i)内有没有和nums[i]相等的元素，有就判定为重复
    bool isRepeat(const vector<int>& nums, int start, int end){
        for(int i = start;i < end; i++){
            if(nums[i] == nums[end])return false;
        }
        return true;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end

