/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyNum(ratings.size(), 1);
        //从左到右，判断左小于右的情况
        for(int i = 0; i < ratings.size() - 1; i++){
            if(ratings[i] < ratings[i + 1])candyNum[i + 1] = candyNum[i] + 1; 
        }
        //从右到左，判断右小于左的情况，注意此时的左可能已经在第一次循环时增加了数量
        //所以要判断此时candyNum[左] 和candyNum[右] + 1的大小，取较大一个即可
        for(int i = ratings.size() - 1; i > 0; --i){
            if(ratings[i] < ratings[i - 1])candyNum[i - 1] = max(candyNum[i - 1], candyNum[i] + 1);
        }
        int sum = 0;
        for(int i = 0;i < candyNum.size(); ++i)sum += candyNum[i];
        return sum;
    }
};
// @lc code=end

