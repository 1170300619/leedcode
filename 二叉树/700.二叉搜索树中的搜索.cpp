/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* cur = root;
        if(root == NULL)return NULL;
        while (cur->val != val)
        {
            if(cur->val == val){
                break;
            }
            else if(cur->val > val){
                if(cur->left != NULL)cur = cur->left;
                else return NULL;   
            }
            else if(cur->val < val){
                if(cur->right != NULL)cur = cur->right;
                else return NULL;
            }
        }
        return cur;
    }
};
// @lc code=end

