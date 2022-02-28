/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cur_five = 0;
        int cur_ten = 0;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5)cur_five++;
            else if(bills[i] == 10 && cur_five > 0){
                cur_five--;
                cur_ten++;
            }
            else if (bills[i] == 20)
            {
                if(cur_ten > 0 && cur_five > 0){
                    cur_five--;
                    cur_ten--;
                }else if (cur_ten <= 0 && cur_five >= 3)
                {
                    cur_five -= 3;
                }
                else return false;
            }else return false;
        }
        return true;
    }
};
// @lc code=end

