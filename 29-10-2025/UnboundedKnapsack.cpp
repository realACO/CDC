#include<bits/stdc++.h>
using namespace std;
int helper(int ind, int W, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
    if(ind==0){
        if(W>=weight[ind])return profit[ind]*W/weight[ind];
        return 0;
    }
    if(dp[ind][W]!=-1)return dp[ind][W];
    int p=0;
    if(W>=weight[ind])p=profit[ind]+helper(ind,W-weight[ind],profit,weight,dp);
    int np=helper(ind-1,W,profit,weight,dp);
    return dp[ind][W]=max(p,np);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return helper(profit.size()-1,w,profit,weight,dp);
}




class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<int> dp(capacity+1,0);
        for(int i=0;i<=capacity;i++){
            dp[i]=val[0]*((int)i/wt[0]);
        }
        for(int i=1;i<wt.size();i++){
            for(int j=0;j<=capacity;j++){
                int np=dp[j];
                int p=0;
                if(j>=wt[i])p=dp[j-wt[i]]+val[i];
                dp[j]=max({p,np});
            }
        }
        return dp[capacity];
    }
};