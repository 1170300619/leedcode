/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
static bool cmp(int a ,int b){
    return abs(a) > abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(k > 0 && nums[i] < 0){
                nums[i] = -nums[i];
                k--;
            }
        }
        if(k > 0 && k % 2 == 1)nums[nums.size() - 1] *= (-1);
        for(int i : nums)ans += i;
        return ans;
    }
};
// @lc code=end

