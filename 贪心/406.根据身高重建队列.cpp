/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0])return a[1] < b[1];
        return a[0] > b[0];
    }
    public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> result;
        for(int i = 0; i < people.size(); i++){
            list<vector<int>>::iterator it = result.begin();
            int position = people[i][1];
            while (position--)
            {
                it++;
            }
            result.insert(it, people[i]);
        }
        return vector<vector<int>> (result.begin(), result.end());
    }
};
//按照身高排序之后，优先按身高高的people的k来插入
//后序插入节点也不会影响前面已经插入的节点!!!
// @lc code=end

