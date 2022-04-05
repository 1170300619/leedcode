/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
    vector<vector<string>> result;
    vector<string> path;
    bool isPalindrome(const string& s, int start, int end){
        for(int i = start, j = end; i <= j; i++, j--){
            if(s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
    void backtracking(const string& s, int startIndex)
    {
        if(startIndex >= s.length()){
            result.push_back(path);
            return ;
        }
        for(int i = startIndex; i < s.length(); i++){
            if(isPalindrome(s, startIndex, i)){
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }else{
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        } 
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};
// @lc code=end

