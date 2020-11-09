import org.graalvm.compiler.core.common.alloc.Trace;

/*
 * @lc app=leetcode.cn id=28 lang=java
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.isEmpty()){
            return 0;
        }
        int length1 = haystack.length();
        int length2 = needle.length();
        for(int i = 0;i<length1;i++){
            if(haystack.charAt(i) == needle.charAt(0)){
                if(i + length2 - 1< length1 && haystack.substring(i, i + length2).equals(needle)){
                    return i;
                }
            }
        }
        return -1;
    }
}
// @lc code=end

