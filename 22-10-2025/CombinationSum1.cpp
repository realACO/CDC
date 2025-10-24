#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int c,int t,int s,vector<vector<int>> &ans,vector<int> &a,vector<int> &b){
        if(t==s){
            ans.push_back(a);
            return;
        }
        if(s>t||c>=b.size())return;

        a.push_back(b[c]);
        dfs(c,t,s+b[c],ans,a,b);
        a.pop_back();
        dfs(c+1,t,s,ans,a,b);
    }
    //given candidate we need to return the vector of all the possible combination
    //we can use the same elements as many times we want till the target is acheiveed
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> a;
        dfs(0,target,0,ans,a,candidates);
        return ans;
    }
};