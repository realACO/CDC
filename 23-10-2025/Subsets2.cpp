#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backtrack(int ind,vector<int> &a,vector<int>& nums,set<vector<int>> &ans){
        if(ind==nums.size()){
            ans.insert(a);
            return;
        }
        a.push_back(nums[ind]);
        backtrack(ind+1,a,nums,ans);
        a.pop_back();
        backtrack(ind+1,a,nums,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> a;
        backtrack(0,a,nums,ans);
        vector<vector<int>> res;
        for(auto i:ans)res.push_back(i);
        return res;
    }
};