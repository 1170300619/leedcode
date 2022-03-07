/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* construct(vector<int>& nums, int left, int right){
        if(left == right)return NULL;//这里是指划分的区域没有元素

        //分割点
        int maxValueIndex = left;
        for(int i = left; i < right; ++i){
            if(nums[i] > nums[maxValueIndex])maxValueIndex = i;
        }

        TreeNode* root = new TreeNode(nums[maxValueIndex]);//根节点

        //关键还是左闭右开区间，这样如果左右相等，则区间内不包含任何元素
        root->left = construct(nums, left, maxValueIndex);
        root->right = construct(nums, maxValueIndex + 1, right);

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums,0,nums.size());
    }
};
// @lc code=end

