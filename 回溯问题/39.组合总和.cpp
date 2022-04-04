/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {

//用set保存已经有的答案，每次找到新的答案后，去set里面找是否已经重复，不重复就再次加入答案和set

// private:
//     vector<vector<int>> result;
//     vector<int> path;
//     set<vector<int>> isAnser;
//     void backtracking(const int& target, int sum, vector<int>& candidates){
//         if(sum == target){
//             vector<int> index = path;
//             sort(index.begin(), index.end());
//             if(isAnser.find(index) == isAnser.end()){
//                 result.push_back(path);
//                 isAnser.insert(index);
//             }
//             return;
//         }
//         else if(sum > target){
//             return;
//         }
//         int n = candidates.size();
//         for(int i = 0; i < n; i++){
//             sum += candidates[i];
//             path.push_back(candidates[i]);
//             backtracking(target, sum, candidates);
//             sum -= candidates[i];
//             path.pop_back();
//         }
//     }
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         result.clear();
//         path.clear();
//         isAnser.clear();
//         backtracking(target, 0, candidates);
//         return result;
//     }



//常用套路：对总集合排序后，进行剪枝

private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(const int& target, int sum, int startIndex, vector<int>& candidates){
        if(sum == target){
            result.push_back(path);
            return;
        }
        int n = candidates.size();
        for(int i = startIndex; i < n && sum + candidates[i] <= target; i++){
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(target, sum, i, candidates); //从i开始
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end()); // 对总集合排序
        backtracking(target, 0, 0, candidates);
        return result;
    }
};
// @lc code=end

