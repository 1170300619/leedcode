/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> str;
        str.push(s[0]);
        for(int i = 1; i < s.length(); i++){
            if(str.empty()){
                str.push(s[i]);
            }
            else if(s[i] == str.top()){
                str.pop();
            }else{
                str.push(s[i]);
            }
        }
        string result = "";
        while (!str.empty())
        {
            result += str.top();
            str.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

