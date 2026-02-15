#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool helper(int ind, vector<int> &nums, vector<int> &dp){
        if(ind==nums.size()-1)return true;
        if(ind>=nums.size())return false;
        if(nums[ind]==0)return false;
        if(dp[ind]!=-1)return dp[ind];
        int x=ind+nums[ind];
        for(int i=ind+1;i<=x;i++){
            if(i<nums.size()){
                if(helper(i,nums,dp))return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(0,nums,dp);
    }
};