/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    //递归方法：技巧是回溯法，这里的回溯是 path + "->",使得path并没有变化
    //这样递归返回后还是原来的path
    void traversal(TreeNode* node, vector<string>& result, string path){
        path += to_string(node->val);
        if(node->left == NULL && node->right == NULL){
            result.push_back(path);
            return;
        }
        if(node->left){
            traversal(node->left, result, path + "->");
        }
        if(node->right){
            traversal(node->right, result, path + "->");
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == NULL)return result;
        string path;
        traversal(root, result, path);
        return result;
    }

    //迭代法：维护一个path栈和节点栈
    //通过判断左右子树都无的情况下其为叶子节点，则将此时的path加入结果中
    // public:
    // vector<string> binaryTreePaths(TreeNode* root) {
    //     stack<TreeNode*> treeStk;
    //     vector<string> result;
    //     stack<string> pathStk;
    //     if(root == nullptr)return result;
    //     treeStk.push(root);
    //     pathStk.push(to_string(root->val));
    //     while (!treeStk.empty())
    //     {
    //         TreeNode* cur = treeStk.top();
    //         treeStk.pop();
    //         string path = pathStk.top();
    //         pathStk.pop();

    //         if(cur->left == NULL && cur->right == NULL) {
    //             result.push_back(path);
    //         }
    //         if(cur->left){
    //             treeStk.push(cur->left);
    //             pathStk.push(path + "->" + to_string(cur->left->val));
    //         }
    //         if(cur->right){
    //             treeStk.push(cur->right);
    //             pathStk.push(path + "->" + to_string(cur->right->val));
    //         }
    //     }
    //     return result;
    // }
};
// @lc code=end

