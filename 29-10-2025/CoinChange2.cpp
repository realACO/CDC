#include <bits/stdc++.h> 
using namespace std;
//memoization
class Solution {
public:
    int helper(int ind, int target, vector<int> &coins, vector<vector<int>> &dp){
        if(ind==0){
            if(target%coins[ind]==0)return 1;
            return 0;
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int p=0;
        if(target>=coins[ind])p=helper(ind,target-coins[ind],coins,dp);
        int np=helper(ind-1,target,coins,dp);
        return dp[ind][target]=p+np;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return helper(coins.size()-1,amount,coins,dp);
        
    }
};


//tabulation
class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        vector<vector<int>> dp(coins.size(), vector<int>(sum+1,0));
        for(int i=0;i<=sum;i++){
            if(i%coins[0]==0)dp[0][i]=i/coins[0];
            else{
                dp[0][i]=1e9;
            }
        }
        
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=sum;j++){
                int p=1e9;
                if(j>=coins[i])p=1+dp[i][j-coins[i]];
                int np=dp[i-1][j];
                dp[i][j]=min(p,np);
            }
        }
        
        if(dp[coins.size()-1][sum]==1e9)return -1;
        return dp[coins.size()-1][sum];
    }
};

