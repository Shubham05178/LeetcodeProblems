/**
* Leetcode Problem - https://leetcode.com/problems/implement-queue-using-stacks/
* Author - Shubham Nagaria
* Date - 6th Feb 2022
**/
class MyQueue {
public:
     stack<int>st1,st2;
    MyQueue() {
        while(!st1.empty())
            st1.pop();
        while(!st2.empty())
            st2.pop();
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int x= st2.top();
        st2.pop();
        return x;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
    bool empty() {
        if(st2.empty() && st1.empty())
            return true;
        return false;
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
