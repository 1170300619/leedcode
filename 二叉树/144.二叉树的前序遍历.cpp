/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    void traversal(TreeNode* cur, vector<int>& vec){
        vec.push_back(cur->val);
        if(cur->left != NULL)traversal(cur->left, vec);
        if(cur->right != NULL)traversal(cur->right, vec);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        if(root == NULL)return vec;
        traversal(root, vec);
        return vec;
    }
};
// @lc code=end

