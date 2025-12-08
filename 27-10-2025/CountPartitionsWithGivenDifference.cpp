#include <bits/stdc++.h> 
using namespace std;
int helper(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp){
    if(sum<0)return 0;
    //handling leading zeros;
    if(ind==0){
        if(sum==0 && arr[ind]==0)return 2;
        if(sum==0)return 1;
        if(sum==arr[0])return 1;        
        return 0;
    }
    if(dp[ind][sum]!=-1)return dp[ind][sum];
    int p=helper(ind-1,sum,arr,dp);
    if(arr[ind]<=sum)p+=helper(ind-1,sum-arr[ind],arr,dp);
    return dp[ind][sum]=(p)%1000000007;
}
int countPartitions(int n, int d, vector<int> &arr) {
    int t=0;
    for(int i:arr)t+=i;
    vector<vector<int>> dp(n,vector<int>(t+1,-1));
    if((t-d)<0 || (t-d)%2==1)return 0;
    return helper(n-1,(t-d)/2,arr,dp);
}




class Solution {
  private:
    int helper(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp){
        if(sum<0)return 0;
        if(ind==0){
            if(sum==0 && arr[ind]==0)return 2;
            if(sum==0)return 1;
            if(sum==arr[ind])return 1;
            return 0;
        }
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        int p=helper(ind-1, sum-arr[ind], arr,dp);
        int np=helper(ind-1, sum, arr,dp);
        return dp[ind][sum]=p+np;
    }
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int t=0;
        for(int i=0;i<arr.size();i++)t+=arr[i];
        if((t-diff)%2==1)return 0;
        if((t-diff)<0)return 0;
        t=(t-diff)/2;
        vector<vector<int>> dp(arr.size(),vector<int>(t+1,-1));
        return helper(arr.size()-1,t,arr,dp);
    }
};