#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i:asteroids){
            //directly push all the positive numbers no matter whateer is in the stack
            if(i>0){
                s.push(i);
                continue;
            }

            //all the cases for negative number
            while(!s.empty() && abs(i)>abs(s.top()) && s.top()>0) s.pop();//pops out all the positive elements from tos whose abs value is less than abs value of current element

            if(s.empty() || s.top()<0) s.push(i);//check after poping elements that if the stack is empty or the tos is negative number and if so then push th negative number into ths stack

            else if(s.top()>0 && abs(s.top())==abs(i))s.pop();
            //last check if the abs value of current element is equal to tos and if so simply pop the tos
        }


        if(s.empty())return {};

        //pop all elements of stack to the result vector
        vector<int> a;
        while(!s.empty()){
            a.push_back(s.top());
            s.pop();
        }   


        // reverse it and return
        reverse(a.begin(), a.end());
        return a;                       
    }
};