#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int MaxSum(int ind, vector<int> &nums, vector<int> &dp){
        if(ind>=nums.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int x=nums[ind]+MaxSum(ind+2,nums,dp);
        int y=MaxSum(ind+1,nums,dp);
        return dp[ind]=max(x,y);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return MaxSum(0,nums,dp);
    }
};