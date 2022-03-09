/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* traversal(TreeNode* root, int key){
        if(root == NULL)return NULL;
        if(root->val == key){
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left != NULL && root->right == NULL){
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else if(root->right != NULL && root->left == NULL){
                TreeNode* right = root->right;
                delete root;
                return right;
            }
            else if(root->left != NULL && root->right != NULL){
                TreeNode* cur = root->right;
                while (cur->left != NULL)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                //下面涉及到tmp的两句可有可无，但因为是C++,还是写上吧
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }

        if(root->val < key)root->right = traversal(root->right, key);
        if(root->val > key)root->left = traversal(root->left, key);
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return traversal(root, key);
    }
};
// @lc code=end

