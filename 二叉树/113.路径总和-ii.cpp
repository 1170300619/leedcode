/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<int> path;
    void traversal(TreeNode* cur, vector<vector<int>> &result, const int& targetSum, int sum){
        if(cur->left == NULL && cur->right == NULL){
            if(sum + cur->val == targetSum){
                path.push_back(cur->val);
                result.push_back(path);
                path.pop_back();
                return;
            }else return;
        }

        if(cur->left){
            path.push_back(cur->val);
            traversal(cur->left, result, targetSum, sum + cur->val);
            path.pop_back();
        }

        if(cur->right){
            path.push_back(cur->val);
            traversal(cur->right, result, targetSum, sum + cur->val);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        path.clear();//这句是关键，每次运行要清空
        int sum = 0;
        if(root == NULL)return result;
        traversal(root, result, targetSum, sum);
        return result;
    }
};
// @lc code=end

