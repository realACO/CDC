#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int helper(int ind, vector<int> &nums, vector<int> &dp){
        if(ind==nums.size()-1)return 0;
        if(ind>=nums.size())return 1e9;
        if(nums[ind]==0)return 1e9;
        if(dp[ind]!=-1)return dp[ind];
        int t=1e9;
        for(int i=ind+1;i<=ind+nums[ind];i++){
            if(i<nums.size()){
                t=min(t,helper(i,nums,dp)+1);
            }
        }
        return dp[ind]=t;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(0,nums,dp);
    }
};