/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
// public:
//     string tmp;
//     vector<string> res;
//     vector<string> board = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//     void DFS(int pos, string digits)
//     {
//         if (pos == digits.size())
//         {
//             res.push_back(tmp);
//             return;
//         }
//         int num = digits[pos] - '0';
//         for (int i = 0; i < board[num].size(); i++)
//         {
//             tmp.push_back(board[num][i]);
//             DFS(pos + 1, digits);
//             tmp.pop_back();
//         }
//     }
//     vector<string> letterCombinations(string digits)
//     {
//         if (digits.size() == 0)
//             return res;
//         DFS(0, digits);
//         return res;
//     }

private:
    vector<string> num = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    string path;
    void backtracking(string digits, int startIndex){
        if(path.size() == digits.length()){
            result.push_back(path);
            return;
        }
        int pos = digits[startIndex] - '0'; //得到对应数字
        for(int i = 0; i < num[pos].length(); i++){
            path.push_back(num[pos][i]);
            backtracking(digits, startIndex + 1);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits){
        result.clear();
        path.clear();
        int k = digits.length();
        if(k == 0)return result;
        backtracking(digits, 0);
        return result;
    }
};
// @lc code=end
