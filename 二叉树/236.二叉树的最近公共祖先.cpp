/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    //如果要遍历整棵树，则设置分别遍历root->left和root->right，最后再对这两者进行逻辑处理
    //如果只需要搜索一条边则，写为if (递归函数(root->left)) return ; if (递归函数(root->right)) return ;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != NULL && right != NULL)return root;
        if(left == NULL && right != NULL)return right;
        else if(left != NULL && right == NULL)return left;
        else return NULL;
    }
};
// @lc code=end

