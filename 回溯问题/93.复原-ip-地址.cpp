/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
    vector<string> result;
    bool isValid(const string& s, int begin, int end)
    {
        if(s[begin] == '0'){
            if(begin == end)return true;
            else return false;
        }else{
            if(end - begin <= 2 && end >= begin){
                string str = s.substr(begin, end - begin + 1);
                int index = std::stoi(str);
                if(index > 0 && index <= 255){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }
    void backtracking(string& s, int startIndex, int pointNum){
        if(pointNum == 3){
            if(isValid(s, startIndex, s.length() - 1))
            {
                result.push_back(s);
            }
            return;
        }

        for(int i = startIndex; i < s.length(); i++){
           if(isValid(s, startIndex, i)){
               s.insert(s.begin() + i + 1, '.');
               pointNum++;
               backtracking(s, i + 2, pointNum);
               pointNum--;
               s.erase(s.begin() + i + 1);
           }
           else{
               break;
           }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if(s.length() > 12) return result;
        backtracking(s, 0, 0);
        return result;
    }
};
// @lc code=end

