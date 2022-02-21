/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int left = -1,right = 0;
        for(int i = s.size() - 1; i>= 0; i--){
            if(s[i] != ' '){
                right = i;
                for(int j = right;j >= 0;j--){
                    if(s[j] != ' ')continue;
                    else{
                        left = j;
                        break;
                    }
                }
                break;
            }else{
                continue;
            }
        }
        return right - left;
    }
};
// @lc code=end

