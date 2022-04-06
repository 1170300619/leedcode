/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    queue<int> stIn;
    queue<int> stOut;
    MyStack() {

    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        int index = stIn.back();
        int size = stIn.size();
        for(int i = 0; i < size - 1; i++){
            stOut.push(stIn.front());
            stIn.pop();
        }
        stIn.pop();
        stIn = stOut;
        while (!stOut.empty())
        {
            stOut.pop();
        }
        return index;
    }
    
    int top() {
        int index= stIn.back();
        return index;
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

