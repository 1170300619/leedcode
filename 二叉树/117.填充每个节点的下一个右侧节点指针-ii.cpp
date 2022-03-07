/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        Node* cur_node = NULL;
        if(root == NULL)return cur_node;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for(int i = 0; i < size; i++){
                cur_node = que.front();
                que.pop();
                if(cur_node->left)que.push(cur_node->left);
                if(cur_node->right)que.push(cur_node->right);
                if(i == size - 1){
                    cur_node->next = NULL;
                    break;
                }
                cur_node->next = que.front();
            }
        }
        return root;
    }
};
// @lc code=end

