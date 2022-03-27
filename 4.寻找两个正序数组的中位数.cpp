/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start

include<iostream>

class Solution {
public:


    //单纯的归并排序，然后找中间的数字
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int m = nums1.size();
    //     int n = nums2.size();
    //     vector<int> v(m + n, -1);
    //     int i = 0, j = 0, k = 0;
    //     while (i < m && j < n)
    //     {
    //         v[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
    //     }
    //     while (i < m)
    //     {
    //         v[k++] = nums1[i++];
    //     }
    //     while (j < n)
    //     {
    //         v[k++] = nums2[j++];
    //     }
    //     return k % 2 ? v[k / 2] : (v[k / 2 - 1] + v[k / 2]) / 2.0f;   
    // }
    
};
// @lc code=end

