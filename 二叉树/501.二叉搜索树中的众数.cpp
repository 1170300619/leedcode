/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    void traversal(TreeNode* root, unordered_map<int,int>& map){
        if(root == NULL)return;
        traversal(root->left, map);
        map[root->val]++;
        traversal(root->right, map);
    }
    //记住cmp作为sort的第三个参数，如果是写在类内，要改成static的，这样和普通函数指针没有区别
    bool static cmp(const pair<int,int>&a, const pair<int,int>& b){
        return a.second > b.second;
    }
public:
    vector<int> findMode(TreeNode* root){
        vector<int> result;
        unordered_map<int,int> map;
        if(root == NULL)return result;
        traversal(root, map);
        vector<pair<int,int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp);
        result.push_back(vec[0].first);
        for(int i = 1; i < vec.size(); i++){
            if(vec[i].second == vec[0].second){
                result.push_back(vec[i].first);
            }
        }
        return result;
    }
//迭代法：每次计算当前数值的count，如果和maxCount相等，则将当前数值加入结果
//如果当前的大于maxCount说明之前的结果都不对，result清空，并且加入当前值，并更新maxCount
// public:
//     vector<int> findMode(TreeNode* root) {
//         stack<TreeNode*> stk;
//         TreeNode* pre = NULL;
//         vector<int> result;
//         if(root == NULL)return result;
//         TreeNode* cur = root;
//         int count = 0;
//         int maxCount = 0;
//         while (!stk.empty() || cur != NULL)
//         {
//             if(cur != NULL){
//                 stk.push(cur);
//                 cur = cur->left;
//             }else{
//                 cur = stk.top();
//                 stk.pop();
//                 if(pre == NULL)count = 1;
//                 else if(pre->val == cur->val)count++;
//                 else if(pre->val != cur->val)count = 1;

//                 //这里push_back的一定是cur->val，因为下一个判断中放的是cur->val
//                 //这里如果放的是pre->val，则重复放置了
//                 if(count == maxCount)result.push_back(cur->val);
//                 if(count > maxCount){
//                     maxCount = count;
//                     result.clear();
//                     //这里一定是cur->val，因为第一个数会进入这个循环，
//                     //而此时pre为空，所以要放入cur->val
//                     result.push_back(cur->val);
//                 }

//                 pre = cur;
//                 cur = cur->right;
//             }
//         }
//         return result;
//     }
};
// @lc code=end

