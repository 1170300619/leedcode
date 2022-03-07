/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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

    //层序迭代法
// public:
//     int countNodes(TreeNode* root) {
//         queue<TreeNode*> que;
//         int sum = 0;
//         if(root == NULL)return sum;
//         que.push(root);
//         TreeNode* cur;
//         while (!que.empty())
//         {
//             int size = que.size();
//             for(int i = 0; i < size; i++){
//                 cur = que.front();
//                 que.pop();
//                 if(cur->left)que.push(cur->left);
//                 if(cur->right)que.push(cur->right);
//                 sum++;
//             }
//         }
//         return sum;
//     }

    //递归方法：
    public:
    int countNodes(TreeNode* root) {
        if(root == NULL)return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftHeight = 0, rightHeight = 0;
        while (left)
        {
            left = left->left;
            leftHeight++;
        }
        while (right)
        {
            right = right->right;
            rightHeight++;
        }
        if(leftHeight == rightHeight){
            return (2 << leftHeight) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
        
    }
};
// @lc code=end

