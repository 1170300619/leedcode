/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    vector<int> getMoney(TreeNode* cur){
        if(cur == NULL)return vector<int>{0, 0};
        vector<int> left = getMoney(cur->left);
        vector<int> right = getMoney(cur->right);
        
        int grab = cur->val + left[0] + right[0];
        int nograb = max(left[0], left[1]) + max(right[0], right[1]);

        return {nograb, grab};
    }
public:
    int rob(TreeNode* root) {
        vector<int> dp = getMoney(root);
        return max(dp[0], dp[1]);
    }
};
// @lc code=end

