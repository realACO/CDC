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
        dfs(c+1,t,s+b[c],ans,a,b);
        a.pop_back();
        while(c+1<b.size()&&b[c]==b[c+1])c++;
        dfs(c+1,t,s,ans,a,b);
    }
    //given candidate we need to return the vector of all the possible combination
    //we cant use the same elements , but if there are duplicates in given vector then we can use it
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> a;
        dfs(0,target,0,ans,a,candidates);
        return ans;
    }
};
//use the same logic as comb sum 1 but we sort the given array first and skip the duplicate elements before the second backtracking call