/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> result;
        if(root == NULL)return result;
        que.push(root);
        Node* cur;
        while (!que.empty())
        {
            vector<int> vec;
            int size = que.size();
            for(int i = 0; i < size; ++i){
                cur = que.front();
                que.pop();
                vec.push_back(cur->val);
                for(int j = 0; j < cur->children.size(); ++j){
                    if(cur->children[j])que.push(cur->children[j]);
                }
            }
            result.push_back(vec);
        }
        return result;       
    }
};
// @lc code=end

