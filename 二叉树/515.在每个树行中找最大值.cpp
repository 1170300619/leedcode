/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> result;
        if(root != NULL)que.push(root);
        TreeNode* cur;
        int max_num = INT32_MIN;
        while (!que.empty())
        {
            int size = que.size();
            for(int i = 0; i < size; i++){
                cur = que.front();
                que.pop();
                max_num = max(max_num, cur->val);
                if(cur->left)que.push(cur->left);
                if(cur->right)que.push(cur->right);
            }
            result.push_back(max_num);
            max_num = INT32_MIN;
        }
        return result;
    }
};
// @lc code=end

