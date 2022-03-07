/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
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
    //递归方法：和找二叉树的相似
//     int max_depth(Node* cur){
//         if(cur == NULL)return 0;
//         int depth = 0;
//         for(int i  = 0; i< cur->children.size(); i++){
//             depth = max(depth, max_depth(cur->children[i]));
//         }
//         return 1 + depth;
//     }
// public:
//     int maxDepth(Node* root) {
//         if(root == NULL)return 0;
//         int result = max_depth(root);
//         return result;
//     }

//迭代方法：基本思路还是层序遍历，记录层数即可
public:
    int maxDepth(Node* root){
        queue<Node*> que;
        if(root == NULL)return 0;
        que.push(root);
        Node* cur;
        int max_depth = 0;
        while (!que.empty())
        {
            int size = que.size();
            max_depth++;
            for(int i = 0; i < size; i++){
                cur = que.front();
                que.pop();
                for(int j = 0; j < cur->children.size(); j++){
                    if(cur->children[j])que.push(cur->children[j]);
                }
            }
        }
        return max_depth;
    }
};
// @lc code=end

