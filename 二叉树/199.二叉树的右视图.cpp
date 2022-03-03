/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> vec;
        if(root == NULL)return vec;
        que.push(root);
        TreeNode* cur;
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                cur = que.front();
                que.pop();
                if(i == (size - 1))vec.push_back(cur->val);
                if(cur->left)que.push(cur->left);
                if(cur->right)que.push(cur->right);
            }
        }
        return vec;
    }
};
// @lc code=end

