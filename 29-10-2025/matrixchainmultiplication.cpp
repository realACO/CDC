#include<bits/stdc++.h>
using namespace std;
int helper(int i, int j, int *arr, int n, vector<vector<int>> &dp){
    if(i==j)return 0;
    int mini=1e9;
    if(dp[i][j]!=-1)return dp[i][j];
    for(int k=i;k<j;k++){
        int steps=(arr[i-1]*arr[k]*arr[j])+helper(i,k,arr,n,dp)+helper(k+1,j,arr,n,dp);
        mini=min(steps,mini);
    }
    return dp[i][j]=mini;
}
int matrixChainMultiplication(int* arr, int n) {
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return helper(1,n,arr,n,dp);
}



class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                int mini=1e9;
                for(int k=i;k<j;k++){
                    int steps=(arr[i-1]*arr[k]*arr[j])+dp[i][k]+dp[k+1][j];
                    mini=min(steps,mini);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][n-1];
    }
};