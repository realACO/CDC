#include<bits/stdc++.h>
using namespace std;
int helper(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target<0)return 0;
    if(ind==arr.size()){
        if(target==0)return 1;
        return 0;
    }
    if(dp[ind][target]!=-1)return dp[ind][target];
    int ans=helper(ind+1,target-arr[ind],arr,dp);
    ans+=helper(ind+1,target,arr,dp);
    return dp[ind][target]=ans%(1000000007);
}
int findWays(vector<int>& arr, int k)
{
    vector<vector<int>> dp(arr.size()+1,vector<int>(k+1,-1));
	return helper(0,k,arr,dp);
}


int findWays(vector<int>& arr, int k){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(arr[0]<=k)dp[0][arr[0]]+=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            int ans=dp[i-1][j];
            if(j>=arr[i])ans+=dp[i-1][j-arr[i]];
            dp[i][j]=(ans)%1000000007;
        }
    }
    return dp[n-1][k];
}
