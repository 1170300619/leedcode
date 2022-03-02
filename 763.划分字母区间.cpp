/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27] = {-1};
        vector<int> result;
        for(int i = 0; i < s.length(); i++){
            hash[s[i] - 'a'] = i;
        }
        int left = 0, right = 0;
        for(int i = 0; i < s.length(); i++)
        {
            right = max(right, hash[s[i] - 'a']);//这一步很巧妙
            if(i == right){
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};
// @lc code=end

