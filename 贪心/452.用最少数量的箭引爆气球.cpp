/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[1] == b[1])return a[0] < b[0];
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        vector<int> area = {0, 0};
        int result = 1;
        area = points[0];
        for(int i = 1; i < points.size(); ++i){
            if(area[1] >= points[i][0])
            {
                area[0] = max(area[0], points[i][1]);
            }
            else{
                result++;
                area = points[i];
            }
        }
        return result;
    }
};
// @lc code=end

