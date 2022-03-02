/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n / 10 == 0)return n;
        string strnum = to_string(n);
        int flag = -1;
        for(int i = strnum.length() - 1; i > 0; --i){
            if(strnum[i - 1] > strnum[i]){
                flag = i;
                strnum[i - 1]--;
            }
        }
        if(flag != -1){
            for(int i = flag; i < strnum.length(); ++i){
                strnum[i] = '9';
            }
        }
        return stoi(strnum);
    }
};
// @lc code=end

