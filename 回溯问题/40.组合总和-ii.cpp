/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(const vector<int>& candidates, int sum, int startIndex, const int& target, vector<bool>& used){
        if(sum == target){
            result.push_back(path);
            return;
        }

        int n = candidates.size();
        for(int i = startIndex; i < n && sum + candidates[i] <= target; i++){
            if(i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false){
                continue;
            }
            used[i] = true;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, sum, i + 1, target, used);
            sum -= candidates[i];
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, 0, 0, target, used);
        return result;
    }
};
// @lc code=end

