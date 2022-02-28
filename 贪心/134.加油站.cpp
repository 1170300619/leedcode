/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int cur_sum = 0;
        int total_sum = 0;
        for(int i = 0; i < gas.size(); i++){
            cur_sum += gas[i] - cost[i];//记录当前总和，来确定满足的范围
            total_sum += gas[i] - cost[i];//用来计算最终gas之和减去cost之和是否大于等于0
            if(cur_sum < 0){
                start = i + 1;
                cur_sum = 0;
            }
        }
        if(total_sum < 0)return -1;
        return start;
    }
};
// @lc code=end

