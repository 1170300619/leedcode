/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        vector<double> vec;
        if(root == NULL)return vec;
        TreeNode* cur;
        que.push(root);
        double sum = 0.0f;
        while(!que.empty()){
            int size = que.size();
            //double sum = 0.0f;
            for(int i = 0; i < size; ++i){
                cur = que.front();
                sum += cur->val;
                que.pop();
                if(cur->left)que.push(cur->left);
                if(cur->right)que.push(cur->right);
            }
            vec.push_back(sum / size);
            sum = 0.0f;
        }
        return vec;
    }
};
// @lc code=end

