#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> p={{'}','{'},{']','['},{')','('}};
        //maintain all the pairs of the parenthesis
        stack<char> st;
        for(char c:s){
            //iterate string till we find a closing bracket
            if(p.count(c)){
                //p.count(a) return true if a is a key in the map
                if(st.empty()||st.top()!=p[c]){
                    //check if stack is empty of the top of stack is not equal to the value of key that is checked now
                    //if so then return false
                    return false;
                }
                st.pop();
                //pop the tos
            }else{
                st.push(c);
                //push the other opening brackets
            }
        }
        return st.empty();
        //since for evey closing bracket we remove a opening bracket that means at the end the stack should be empty
        //if empty return true
        //if not empty return false
    }
};