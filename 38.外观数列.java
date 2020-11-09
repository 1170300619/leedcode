/*
 * @lc app=leetcode.cn id=38 lang=java
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
    public String countAndSay(int n) {
        String s = "1";
        StringBuffer ans = new StringBuffer("");
        int index = 1;
        while(--n > 0){
            for(int i = 0 ;i < s.length(); i++){
                if(i + 1 < s.length() && s.charAt(i) == s.charAt(i + 1)){
                    index++;
                    continue;
                }
                ans.append(index);
                ans.append(s.charAt(i));
                index = 1;
            }
           /* if(s.length() > 1 && s.charAt(s.length() - 1) != s.charAt(s.length() - 2)){
                ans.append(index);
                ans.append(s.charAt(s.length() - 1));
            }*/
            s = ans.toString();
            ans = new StringBuffer("");
            //System.out.println(s);
        }
        return s;
    }
}
// @lc code=end

