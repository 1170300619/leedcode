/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        if(s.length() == 0)return false;
        stk.push(s[0]);
        for(int i = 1;i<s.length();i++){
            if(!stk.empty() && stk.top() == '(' && s[i] == ')'){
                stk.pop();
                continue;
            }
            if(!stk.empty() && stk.top() == '[' && s[i] == ']'){
                stk.pop();
                continue;
            }
            if(!stk.empty() && stk.top() == '{' && s[i] == '}'){
                stk.pop();
                continue;
            }
            stk.push(s[i]);
        }
        if(!stk.empty())return false;
        return true;
    }
};
// @lc code=end

