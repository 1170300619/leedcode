/*
 * @lc app=leetcode.cn id=5 lang=java
 *
 * [5] 最长回文子串
 */

// @lc code=start
//动态规划方法
/*
class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        boolean [][] dp = new boolean [n][n];
        String ans = "";
        for(int l = 0 ; l < n ; l++){ //l用来记录当前可能的字串长度
            for(int i=0;i<n-l;i++){
                int j = i+l;
                if(l == 0){ //当前可能字串长度为1，则一定是回文子串
                    dp[i][j] = true;
                }else if(l == 1){ // 当前可能字串长度为2，则在两个字母相同的情况下为真
                    dp[i][j] = (s.charAt(i) == s.charAt(j));
                }else { //当前可能字串长度大于2，则利用状态转移公式判断是否为回文字串
                    dp[i][j] = (s.charAt(i) == s.charAt(j) && dp[i+1][j-1]);
                }
                if(l + 1 > ans.length() && dp[i][j]){
                    ans = s.substring(i,i + l + 1);
                }
            }
        }
        return ans;
    }
}*/
//中心扩展方法
class Solution {
    public String longestPalindrome(String s) {
        if(s == null || s.length() < 1){
            return "";
        }
        int n = s.length();
        int len = 0;
        int left = 0,right = 0;
        String ans = "";
        for(int i = 0;i<n;i++){
            int len1 = expandAroundCenter(s,i,i);
            int len2 = expandAroundCenter(s,i,i+1);
            len = Math.max(len1,len2);
            if(len > right - left){
                //边界控制！！！
                left = i - (len - 1)/2;
                right = i + len / 2; 
            }
        }
        //substring结束索引不包括，所以right+1
        return s.substring(left,right + 1);
    }
    public int expandAroundCenter(String s,int left,int right){
        while(left >=0 && right < s.length()  && s.charAt(left) == s.charAt(right)){
            left--;
            right++;
        }
        //精准控制边界条件
        return right - left - 1;
    }
}
// @lc code=end

