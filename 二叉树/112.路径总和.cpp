/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool getSum(TreeNode* cur, int sum, const int& targetSum){
        if(cur->left == NULL && cur->right == NULL){
            if(sum + cur->val == targetSum)return true;
            else return false;
        }
        if(cur->right){
            if(getSum(cur->right, sum + cur->val, targetSum))return true;
        }
        if(cur->left){
            if(getSum(cur->left, sum + cur->val, targetSum))return true;
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)return false;
        int sum = 0;
        return getSum(root, sum, targetSum);
    }
};
// @lc code=end

