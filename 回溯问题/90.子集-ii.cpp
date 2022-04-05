/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex, vector<bool> used){
        result.push_back(path);
        for(int i = startIndex; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false){
                continue;
            }
            else{
                path.push_back(nums[i]);
                used[i] = true;
                backtracking(nums, i + 1, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        result.clear();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return result;
    }
};
// @lc code=end

