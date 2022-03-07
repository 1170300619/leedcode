/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    //递归方法：一般情况下只需要判断cur就可以，不用去判断cur的子节点是否为NULL
//     void reverse_child(TreeNode* cur){
//         if(cur == NULL)return;
//         swap(cur->left, cur->right);
//         reverse_child(cur->left);
//         reverse_child(cur->right);
//     }
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(root == NULL)return NULL;
//         reverse_child(root);
//         return root;
//     }

    //层序遍历方法
    // public:
    //     TreeNode* invertTree(TreeNode* root){
    //         if(root == NULL)return NULL;
    //         queue<TreeNode*> que;
    //         que.push(root);
    //         TreeNode* cur;
    //         while (!que.empty())
    //         {
    //             int size = que.size();
    //             for(int i = 0; i < size; i++){
    //                 cur = que.front();
    //                 que.pop();
    //                 //先交换，因为可能存在某个子节点为NULL的情况
    //                 swap(cur->left, cur->right);
    //                 if(cur->left)que.push(cur->left);
    //                 if(cur->right)que.push(cur->right);
    //             }
    //         }
    //         return root;
    //     }
    //
    //迭代法：交换后，先放右子节点，再放左子节点
    public:
        TreeNode* invertTree(TreeNode* root){
            if(root == NULL)return NULL;
            stack<TreeNode*> stk;
            stk.push(root);
            TreeNode* cur;
            while (!stk.empty())
            {
                cur = stk.top();
                stk.pop();
                swap(cur->left, cur->right);
                if(cur->right)stk.push(cur->right);
                if(cur->left)stk.push(cur->left);
            }
            return root; 
        }
};
// @lc code=end

