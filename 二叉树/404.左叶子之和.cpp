/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    //如果该节点是向右子节点得到，则isLeft为false
    //如果该节点是向左子节点得到，则isLeft为true
    //只有isLeft为真，且该节点没有左右子节点，才加上该节点的值
    void getLeft(TreeNode* cur, bool isLeft, int& result){
        if(cur->left == NULL && cur->right == NULL && isLeft){
            result += cur->val;
        }
        if(cur->left){
            getLeft(cur->left, true, result);
        }
        if(cur->right){
            getLeft(cur->right, false, result);
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        bool isLeft = false;
        int result = 0;
        if(root == NULL)return result;
        getLeft(root, isLeft, result);
        return result;
    }
};
// @lc code=end

