/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int getHeight(TreeNode* root){
        if(root == nullptr)return 0; 
        int left = getHeight(root->left);
        if(left == -1)return -1;
        int right = getHeight(root->right);
        if(right == -1)return -1;

        int result = 0;
        if(abs(left - right) > 1)return -1;
        else return max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        if(getHeight(root) >= 0)return true;
        else return false;
    }
};
// @lc code=end

