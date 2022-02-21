import java.awt.List;
import java.util.ArrayList;

import jdk.internal.net.http.common.SequentialScheduler.RestartableTask;

/*
 * @lc app=leetcode.cn id=56 lang=java
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals.length == 0 || intervals == null)return new int[0][2];
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] interval1, int[] interval2) {
                return interval1[0] - interval2[0];
            }
        });
        
        List<int[]> result = new ArrayList<>();
        for(int i = 0 ;i < intervals.length;i++){
            int left = intervals[i][0],right = intervals[i][1];
            if(result.size() == 0 || result.get(result.size() - 1)[1] < left){
                result.add(new int[]{left,right});
            }else{
                result.get(result.size() - 1)[1] = Math.max(result.get(result.size() - 1)[1] ,right);
            }
        }
        return result.toArray(new int[result.size()][]);
    }
}
// @lc code=end

