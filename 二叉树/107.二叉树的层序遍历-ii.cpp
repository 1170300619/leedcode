/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> result;
        //stack<vector<int>> stk;
        if(root == NULL)return result;
        que.push(root);
        TreeNode* cur;
        while (!que.empty())
        {
            vector<int> vec;
            int size = que.size();
            for(int i = 0; i < size; ++i){
                cur = que.front();
                que.pop();
                vec.push_back(cur->val);
                if(cur->left)que.push(cur->left);
                if(cur->right)que.push(cur->right);
            }
            //stk.push(vec);
            result.push_back(vec);
        }
        // while (!stk.empty())
        // {
        //     result.push_back(stk.top());
        //     stk.pop();
        // }
        reverse(result.begin(), result.end());//使用泛型反转函数
        return result;
    }
};
// @lc code=end

