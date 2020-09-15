import javax.lang.model.element.Element;

/*
 * @lc app=leetcode.cn id=9 lang=java
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0){
            return false;
        }else if(x == 0){
            return true;
        }else{
            int length = 0;
            int [] array = new int [10];
            while(x != 0){
                array[length++] = x % 10;
                x /= 10;
            }
            int start = 0,end = length -1;
            int flag = 0;
            while(start <= end){
                if(array[start] == array[end]){
                    start++;
                    end--;
                }else{
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                return false;
            }else{
                return true;
            }
        }
    }
}
// @lc code=end

