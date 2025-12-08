#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int helper(int ind, int target, vector<int> &coins, vector<vector<int>> &dp){
        if(ind==0){
            if(target%coins[ind]==0)return target/coins[ind];
            return 1e9;
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int p=1e9;
        if(target>=coins[ind])p=1+helper(ind,target-coins[ind],coins,dp);
        int np=helper(ind-1,target,coins,dp);
        return dp[ind][target]=min(p,np);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)return 0;
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=helper(coins.size()-1,amount,coins,dp);
        if(ans==1e9)return -1;
        return ans;
    }
};