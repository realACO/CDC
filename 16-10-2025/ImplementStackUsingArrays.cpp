#include <bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int> s;
    MyQueue() {
        
    }
    void push(int x) {
        s.push(x);
    }
    int pop() {
        stack<int> temp;
        while(s.size()!=1){
            temp.push(s.top());
            s.pop();
        }
        int ans=s.top();
        s.pop();
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
        return ans;
    }
    int peek() {
        stack<int> temp;
        while(s.size()!=1){
            temp.push(s.top());
            s.pop();
        }
        int ans=s.top();
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
        return ans;
    }
    bool empty() {
        return s.empty();
    }
};

