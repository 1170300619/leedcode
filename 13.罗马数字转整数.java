/*
 * @lc app=leetcode.cn id=13 lang=java
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
    public int romanToInt(String s) {
        int [] value = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        String [] Roman = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int index = 0;
        int ans = 0;
        String sb = "";
        int flag = 0;
        while(index < s.length() && index + 1 < s.length()){
            sb = s.substring(index, index + 2);
            for(int i=0;i<Roman.length;i++){
                if(Roman[i].equals(sb)){
                    flag = 1;
                    ans += value[i];
                    index += 2;
                    break;
                }
            }
            if(flag == 1){
                flag = 0;
                continue;
            }else if(flag == 0){
                sb = s.substring(index,index + 1);
                for(int i = 0;i<Roman.length;i++){
                    if(Roman[i].equals(sb)){
                        ans += value[i];
                        index++;
                        break;
                    }
                }
            }
        }
        if(index < s.length()){
            for(int i = 0;i<Roman.length;i++){
                sb = s.substring(index, index + 1);
                if(Roman[i].equals(sb)){
                    ans += value[i];
                    break;
                }
            }
        }
        return ans;
    }
}
// @lc code=end

