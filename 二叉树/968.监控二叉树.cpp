/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
private:
    int reslut;
    int travalsal(TreeNode* cur){
        //空节点，该节点定义为有覆盖
        if(cur == NULL)return 2;

        int left = travalsal(cur->left);//左
        int right = travalsal(cur->right);//右

        if(left == 2 && right == 2)return 0;

        if(left == 0 || right == 0){
            reslut++;
            return 1;
        }

        if(left == 1 || right == 1)return 2;

        return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        reslut = 0;
        if(travalsal(root) == 0){
            reslut++;
        }
        return reslut;
    }
};
// @lc code=end

