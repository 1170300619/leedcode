/*
 * @lc app=leetcode.cn id=14 lang=java
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
    public String longestCommonPrefix(String[] strs) {
       // StringBuilder ans = new StringBuilder();
        if(strs.length == 1){
            return strs[0];
        }
        if(strs.length == 0){
            return "";
        }
        String index = strs[0];
        for(int i=1;i<strs.length - 1;i++){
            if(index.length() > strs[i].length()){
                index = strs[i];
            }            
        }
        int flag = 0;
        while(index.length() > 0){
            for(int i = 0;i<strs.length;i++){
                if(strs[i].startsWith(index)){
                    flag = 1;
                    continue;
                }else{
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                return index;
            }else{
                index = index.substring(0, index.length() - 1);
            }
        }
        return "";
    }
}
// @lc code=end

