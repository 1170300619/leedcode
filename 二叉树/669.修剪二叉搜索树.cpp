/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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

//这个题挺难的
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL)return NULL;
        if(root->val < low){
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }
        else if(root->val > high){
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }

        else {
            TreeNode* left = trimBST(root->left, low, high);
            TreeNode* right = trimBST(root->right, low, high);
            root->left = left;
            root->right = right;
        }
        return root;
    }
};
// @lc code=end

