/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
//     //递归方法：分别判断两个内节点和外节点是否相等
//     bool compare(TreeNode* left, TreeNode* right){
//         if(left == NULL && right == NULL)return true;
//         if(left == NULL && right != NULL)return false;
//         if(left != NULL && right == NULL)return false;
//         if(left->val != right->val)return false;
//         bool outside = compare(left->left, right->right);
//         bool inside = compare(left->right, right->left);
//         bool isSame = outside && inside;
//         return isSame;
//     }
// public:
//     bool isSymmetric(TreeNode* root) {
//         if(root == NULL)return true;
//         return compare(root->left,root->right);
//     }

    //迭代方法：每次取出queue的前两个节点作为比较的节点
    public:
        bool isSymmetric(TreeNode* root){
            if(root == NULL)return true;
            queue<TreeNode*> que;
            que.push(root->left);
            que.push(root->right);
            
            while (!que.empty())
            {
                TreeNode* left_tree = que.front();
                que.pop();
                TreeNode* right_tree = que.front();
                que.pop();
                if(!left_tree && !right_tree)continue;

                if((!left_tree || !right_tree) || (left_tree->val != right_tree->val))return false;

                que.push(left_tree->left);
                que.push(right_tree->right);
                que.push(left_tree->right);
                que.push(right_tree->left);
            }
            return true;
        }
};
// @lc code=end

