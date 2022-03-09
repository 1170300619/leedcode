/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
// private:
//     //用vector中序遍历二叉树，如果是二叉搜索树，则中序遍历是严格增序的
//     vector<int> vec;
//     void traversal(TreeNode* cur){
//         if(cur == NULL)return;
//         traversal(cur->left);
//         vec.push_back(cur->val);
//         traversal(cur->right);
//     }
// public:
//     bool isValidBST(TreeNode* root) {
//         vec.clear();
//         traversal(root);
//         bool isValid = true;
//         for(int i = 0; i < vec.size() - 1; i++){
//             if(vec[i] >= vec[i + 1]){
//                 isValid = false;
//                 break;
//             }
//         }
//         return isValid;
//     }

//看不懂这个题解
public:
    TreeNode* pre = NULL;
    bool isValidBST(TreeNode* root){
        if(root == NULL)return true;
        bool left = isValidBST(root->left);

        if(pre != NULL && pre->val >= root->val)return false;
        pre = root;

        bool right = isValidBST(root->right);
        return left && right;
    }
};
// @lc code=end

