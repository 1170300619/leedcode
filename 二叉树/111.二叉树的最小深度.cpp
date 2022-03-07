/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
// public:
//     int minDepth(TreeNode* root) {
//         queue<TreeNode*> que;
//         int min_depth = 0;
//         TreeNode* cur;
//         bool flag = false;
//         if(root != NULL)que.push(root);
//         while (!que.empty())
//         {
//             int size = que.size();
//             min_depth++;
//             for(int i = 0; i < size; i++){
//                 cur = que.front();
//                 que.pop();
//                 if(cur->left)que.push(cur->left);
//                 if(cur->right)que.push(cur->right);
//                 if(cur->left == NULL && cur->right == NULL){
//                     flag = true;
//                 }
//             }
//             if(flag)break;
//         }
//         return min_depth;
//     }

    //递归方法，要注意，如果左右子节点同时存在（或同时不存在）则取最小的
    //如果左右节点只有某一个存在，则取存在的那个，因为这时候不存在的不是叶子节点
    //只有左右子节点同时不存在的节点才是叶子节点
    int min_depth(TreeNode* cur){
        if(cur == NULL)return 0;
        int depth = 0;
        if(cur->left && cur->right)depth = min(min_depth(cur->left), min_depth(cur->right));
        else if(!cur->left && cur->right)depth = min_depth(cur->right);
        else if(!cur->right && cur->left)depth = min_depth(cur->left);
        return depth + 1;
    }
    public:
    int minDepth(TreeNode* root) {
       if(root == NULL)return 0;
       int result = min_depth(root);
       return result;
    }
};
// @lc code=end

