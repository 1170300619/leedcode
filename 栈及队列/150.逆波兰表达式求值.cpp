/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i].size() == 1 && tokens[i] == "+")
            {
                int index = stk.top();
                stk.pop();
                index += stk.top();
                stk.pop();
                stk.push(index);
            }
            else if(tokens[i].size() == 1 && tokens[i] == "-")
            {
                int index = stk.top();
                stk.pop();
                index = stk.top() - index;
                stk.pop();
                stk.push(index);
            }
            else if(tokens[i].size() == 1 && tokens[i] == "*")
            {
                int index = stk.top();
                stk.pop();
                index = index * stk.top();
                stk.pop();
                stk.push(index);
            }else if(tokens[i].size() == 1 && tokens[i] == "/")
            {
                int index = stk.top();
                stk.pop();
                index = stk.top() / index;
                stk.pop();
                stk.push(index);
            }
            else {
                stk.push(std::stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};
// @lc code=end

