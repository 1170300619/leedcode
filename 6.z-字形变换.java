/*
 * @lc app=leetcode.cn id=6 lang=java
 *
 * [6] Z 字形变换
 */

// @lc code=start
/*

//推导公式方法
class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1){
            return s;
        }
        StringBuilder ret = new StringBuilder();
        int index = 2 * numRows - 2;
        int n = s.length();
        for(int i = 0;i < numRows; i++){
            for(int j = 0; j + i < n; j += index){
                ret.append(s.charAt(j + i));
                if(i != 0 && i != numRows - 1 && j + index - i < n){
                    ret.append(s.charAt(j + index - i));
                }
            }
        }
        return ret.toString();
    }
}*/


//列表模拟排列方法
class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1){
            return s;
        }

        List<StringBuilder> l = new ArrayList<>();
        for(int i=0;i<Math.min(s.length(),numRows);i++){
            l.add(new StringBuilder());
        }
        int cur = 0;
        boolean flag = false;

        for(char c : s.toCharArray()){
            l.get(cur).append(c);
            if(cur == 0 || cur == numRows - 1){
                flag = !flag;
            }
            cur += flag ? 1 : -1;
        }
        StringBuilder ans = new StringBuilder();
        for(StringBuilder sb : l){
            ans.append(sb);
        }
        return ans.toString();
    }
}
// @lc code=end

