/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode* traversal(TreeNode* root, TreeNode* cur){
        if(root == NULL)return cur;
        if(root->val > cur->val){
            TreeNode* left = traversal(root->left, cur);
            if(left != NULL){
                root->left = left;
            }
        }
        else if(root->val < cur->val){
            TreeNode* right = traversal(root->right, cur);
            if(right != NULL){
                root->right = right;
            }
        }
        return root;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = new TreeNode(val);
        return traversal(root, cur);
    }
};
// @lc code=end

