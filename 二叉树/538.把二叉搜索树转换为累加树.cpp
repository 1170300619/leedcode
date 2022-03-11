/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
//迭代法套用模板：采用右中左顺序来进行计算即可
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> stk;
        if(root == NULL)return NULL;
        TreeNode* pre = NULL;
        TreeNode* cur = root;
        while (!stk.empty() ||  cur != NULL)
        {
            if(cur != NULL){
                stk.push(cur);
                cur = cur->right;
            }
            else{
                cur = stk.top();
                stk.pop();
                if(pre != NULL){
                    cur->val += pre->val;
                }
                pre = cur;
                cur = cur->left;
            }
        }
        return root;
    }
};
// @lc code=end

