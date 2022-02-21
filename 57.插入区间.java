import java.lang.annotation.Retention;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode.cn id=57 lang=java
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if(intervals.length == 0 || intervals == null){
            if(newInterval.length == 0)return new int[0][2];
            else{
                int[][] tmp = new int[0][2];
                tmp[0][0] = newInterval[0];
                tmp[0][1] = newInterval[1];
                return tmp;
            }
        }

        int[][] index = new int[intervals.length + 1][];
        for(int i = 0 ; i < intervals.length; i++){
            index[i][0] = intervals[i][0];
            index[i][1] = intervals[i][1];
        }
        index[intervals.length][0] = newInterval[0];
        index[intervals.length][1] = newInterval[1];

        Arrays.sort(index , new Comparator<int[]>(){
            public int compare(int[] internal1,int[] interval2){
                return internal1[0] - interval2[0];
            }
        });

        List<int[]> result = new ArrayList<>();

        for(int i = 0; i < index.length;i++){
            int left = index[i][0],right = index[i][1];
            if(result.size() == 0 || result.get(result.size() - 1)[1] < left){
                result.add(new int[]{left,right});
            }else{
                result.get(result.size()-1)[1] = Math.max(result.get(result.size()-1)[1], right);
            }
        }
        return result.toArray(new int[result.size()][]);
    }
}
// @lc code=end

