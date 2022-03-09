/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
private:
//二叉搜索树是有序的，我们只需要从上到下遍历即可
//如果判断至某个节点的值位于我们要找的两个值的闭区间内，则一定是最近公共祖先
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == q || root == p)return root;
        
        if(root->val > max(p->val, q->val)){
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            if(left != NULL)return left;
        }

        else if(root->val < min(p->val, q->val)){
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if(right != NULL)return right;
        }

        return root;
    }
};
// @lc code=end

