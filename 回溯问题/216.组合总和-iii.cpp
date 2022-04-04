/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startIndex){
        if(path.size() == k){
            int sum = 0;
            for(int i = 0; i < path.size(); i++){
                sum += path[i];
            }
            if(sum == n){
                result.push_back(path);
                return;
            }
            return; //如果要从for循环里面剪枝，则这里无论如何都要return，否则接下来还有可能执行for循环
        }

        for(int i = startIndex; i <= 9 - (k - path.size()) + 1; i++){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        path.clear();
        backtracking(n, k, 1);
        return result;
    }
};
// @lc code=end

