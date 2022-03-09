/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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

//使用中序遍历并记录在vector中，接下来只需计算相邻两元素之间的最小差值的绝对值即可
// private:
//     vector<int> vec;
//     void traversal(TreeNode* cur){
//         if(cur == NULL)return;
//         traversal(cur->left);
//         vec.push_back(cur->val);
//         traversal(cur->right);
//     }
// public:
//     int getMinimumDifference(TreeNode* root) {
//         vec.clear();
//         traversal(root);
//         int minDif = INT32_MAX;
//         cout << vec.size() << endl;
//         for(int i = 0; i < vec.size() - 1; i++){
//             minDif = min(minDif, abs(vec[i] - vec[i + 1]));
//         }
//         return minDif;
//     }

//迭代法，还是使用中序遍历
public:
    int getMinimumDifference(TreeNode* root){
        stack<TreeNode*> stk;
        int minDif = INT32_MAX;
        TreeNode* cur = root;
        TreeNode* pre = NULL;//始终保存cur上一个的值
        while (!stk.empty() || cur != NULL)
        {
            if(cur != NULL){
                stk.push(cur);
                cur = cur->left;
            }else{
                cur = stk.top();
                stk.pop();
                if(pre != NULL){
                    minDif = min(minDif, abs(pre->val - cur->val));
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return minDif;
    }
};
// @lc code=end

