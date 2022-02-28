/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int index = 0;
        int sum = 0;
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[index][1] > intervals[i][0])
            {
                sum++;
            }
            else
            {
                index = i;
            }
        }
        return sum;
    }
};
// @lc code=end

