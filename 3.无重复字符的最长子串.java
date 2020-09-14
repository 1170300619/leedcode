/*
 * @lc app=leetcode.cn id=3 lang=java
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> s1 = new HashSet<Character>();
        int p1= -1;
        int result = 0;
        int n = s.length();
        for(int i = 0;i<n;i++){
            if(i != 0){
                s1.remove(s.charAt(i - 1));
            }
            //while语句中注意判断条件的先后顺序，首先判断p1 + 1是否小于n，这样后面的s.chatAt(p1 + 1)才能进行使用，否则将出现错误
            while(p1 + 1 < n && !s1.contains(s.charAt(p1 + 1))){ 
                s1.add(s.charAt(p1 + 1));
                p1++;
            }
            result = Math.max(result,p1 - i + 1);
        }
        return result;
    }
}
// @lc code=end

