/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(const vector<int>& nums, int startIndex, vector<bool>used){
        result.push_back(path);
        for(int i = startIndex; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1] && used[i] == false){
                continue;
            }
            else{
                path.push_back(nums[i]);
                used[i] = true;
                backtracking(nums, i + 1, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return result;
    }
};
// @lc code=end

