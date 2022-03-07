/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
//迭代法：使用层序遍历的方法，找到最大的深度
// public:
//     int maxDepth(TreeNode* root) {
//         queue<TreeNode*> que;
//         int depth = 0;
//         if(root != NULL)que.push(root);
//         TreeNode* cur;
//         while (!que.empty())
//         {
//             int size = que.size();
//             for(int i = 0; i < size; i++){
//                 cur = que.front();
//                 que.pop();
//                 if(cur->left)que.push(cur->left);
//                 if(cur->right)que.push(cur->right);
//             }
//             depth++;
//         }
//         return depth;
//     }

    //递归方法，分别计算左右节点的深度
    int max_depth(TreeNode* cur){
        if(cur == NULL)return 0;
        int left = max_depth(cur->left);
        int right = max_depth(cur->right);
        return 1 + max(left, right);
    }
    public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)return 0;
        int result = max_depth(root);
        return result;
    }
};
// @lc code=end

