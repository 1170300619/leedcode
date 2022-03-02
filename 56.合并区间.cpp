/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0])return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.size() == 0)return result;
        sort(intervals.begin(), intervals.end(), cmp);
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i){
            if(result.back()[1] >= intervals[i][0]){
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
// @lc code=end

