/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& vec1,const vector<int>& vec2){
        return vec1[0] < vec2[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        vector<vector<int>> ans;
        bool flag = false;
        for(const auto& interval: intervals){
            if(interval[1] < left){
                ans.push_back(interval);
            }
            else if(interval[0] > right){
                if(!flag){
                    ans.push_back({left,right});
                    flag = true;
                }
                ans.push_back(interval);
            }else{
                left = min(left,interval[0]);
                right = max(right,interval[1]);
            }
        }
        if(!flag){
            ans.push_back({left,right});
        }
        //ans.push_back({left,right});
        //sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};
// @lc code=end

