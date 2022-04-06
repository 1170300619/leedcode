/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    stack<int> queIn;
    stack<int> queOut;
    MyQueue() {
        
    }
    
    void push(int x) {
        queIn.push(x);
    }
    
    int pop() {
        if(queOut.empty()){
            while (!queIn.empty())
            {
                queOut.push(queIn.top());
                queIn.pop();
            }
        }
        int result = queOut.top();
        queOut.pop();
        return result;
    }
    
    int peek() {
        int result = this->pop();
        queOut.push(result);
        return result;
    }
    
    bool empty() {
        return queIn.empty() && queOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

