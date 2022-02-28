/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)return nums.size();
        int prediff = 0;
        int curdiff = 0;
        int sum = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            curdiff = nums[i + 1] - nums[i];
            if((prediff <= 0 && curdiff > 0) || (prediff >= 0 && curdiff < 0)){
                sum++;
                prediff = curdiff;
            }
        }
        return sum;
    }
};
//用当前差值和之前的插值进行比较，二者之间不同才可，而且对序列为2的进行了特殊处理
// @lc code=end

