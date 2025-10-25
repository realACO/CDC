#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backtrack(int o,int c,int n,string &s,vector<string> &ans){
        if(o==c&&c==n){//base case when open bracket==close bracket==n
            ans.push_back(s);
            return;
        }
        if(o<n){//only add open bracket to the string if o<n
            s+="(";
            backtrack(o+1,c,n,s,ans);//recursively call the fn for o+1
            s.pop_back();//backtrack
        }
        if(c<o){//we only add closed bracket if c<o
            s+=")";
            backtrack(o,c+1,n,s,ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s1="";
        backtrack(0,0,n,s1,ans);
        return ans;
    }
};