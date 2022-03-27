/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int l = s.length();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(l + 1, false);
        dp[0] = true;
        for(int i = 0; i <= l; i++){
            for(int j = 0; j < i; j++){
                string word = s.substr(j, i - j); //起始位置，截取的个数
                if(wordSet.find(word) != wordSet.end() && dp[j]){
                    dp[i] = true;
                }
            }
        }
        return dp[l];
    }
};
// @lc code=end

