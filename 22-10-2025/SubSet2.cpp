#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  void dfs(int i,set<vector<int>> &ans,vector<int> &n,vector<int> &nums){
        if(i>=nums.size()){
            ans.insert(n);
            return;
        }
        n.push_back(nums[i]);
        dfs(i+1,ans,n,nums);
        n.pop_back();
        dfs(i+1,ans,n,nums);
    }
    vector<vector<int>> findSubsets(vector<int>& arr) {
        sort(arr.begin(),arr.end());//sort elements 
        set<vector<int>> ans;//store ans in set so that no duplicates subset can repeat
        vector<int> n;
        dfs(0,ans,n,arr);
        vector<vector<int>> res;//store the elements of set back o vector and return
        for(auto &i:ans)res.push_back(i);
        return res;
    }
};