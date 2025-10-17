//using basic vector operations for push pop and get min function, all this while maintaining size of the arr
//the getMIn function makeds this code slower because of the Onlogn sorting each time and returning the first index
#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
    vector<int> arr;
    int size;
    MinStack() {
        size=0;
    }
    void push(int val) {
        arr.push_back(val);
        size++;
    }
    void pop() {
        arr.erase(arr.begin()+size-1);
        size--;
    }
    int top() {
        return arr[size-1];
    }
    int getMin() {
        vector<int> t=arr;
        sort(t.begin(),t.end());
        return t[0];
    }
};


//slightly btr approach is to use min heap for getmin function
//using map to store the count of all the poped values along with the arr values
//while returning the min element just check is the count of m[q.top()] is greater that 0 and if so that mean the particular value is already poped from the arr and should be remove from the heap as a result, before being remove the m[q.top()] should be decremented
//still this method is ologn time complexity
class MinStack {
public:
    vector<int> arr;
    priority_queue<int,vector<int>,greater<int>> q;
    unordered_map<int,int> m;
    int size;
    MinStack() {
        size=0;
    }
    void push(int val) {
        arr.push_back(val);
        q.push(val);
        size++;
    }
    void pop() {
        m[arr[size-1]]++;
        arr.pop_back();
        size--;
    }
    int top() {
        return arr[size-1];
    }
    int getMin() {
        while(m[q.top()]>0){
            m[q.top()]--;
            q.pop();
        }
        return q.top();
    }
};

//optimal way is to use 2 stacks one for normal operations and other to store the min elemnt stack
class MinStack {
public:
    stack<int> s;
    stack<int> min;
    MinStack() {
    }
    void push(int val) {
        s.push(val);
        if(min.empty()||min.top()>=val)min.push(val);
    }
    void pop() {
        if(min.top()==s.top())min.pop();
        s.pop();
    }
    int top() {
        return s.top();
    }  
    int getMin() {
        return min.top();
    }
};
