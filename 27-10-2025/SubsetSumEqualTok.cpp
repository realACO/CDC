#include <bits/stdc++.h> 
using namespace std;
int helper(int ind, int k, vector<int> &arr,int sum,vector<vector<int>> &dp){
    if(ind>arr.size()){
        return 0;
    }
    if(dp[ind][sum]!=-1){
        return dp[ind][sum];
    }
    if(sum==k){
        return 1;
    }
    int x=helper(ind+1,k,arr,sum+arr[ind],dp);
    int y=helper(ind+1,k,arr,sum,dp);
    return dp[ind][sum]=(x+y);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    int t=0;
    for(auto i:arr)t+=i;
    vector<vector<int>> dp(arr.size()+1,vector<int>(t+1,-1));
    return helper(0,k,arr,0,dp);
}



class Solution {
  private:
    int sequence(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp){
        if(sum==0){
            return 1;
        }
        if(ind>=arr.size() || sum<0){
            return 0;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        int x=sequence(ind+1,sum-arr[ind],arr,dp);
        int y=sequence(ind+1,sum,arr,dp);
        return dp[ind][sum]=(x+y);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1,-1));
        return sequence(0,sum,arr,dp);
    }
};


//tabulation
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1,0));
        for(int i=0;i<arr.size();i++){
            dp[i][0]=1;
        }
        if(arr[0]<=sum)dp[0][arr[0]]=1;
        for(int i=1;i<arr.size();i++){
            for(int j=1;j<=sum;j++){
                int nottake=dp[i-1][j];
                int take=0;
                if(j>=arr[i])take=dp[i-1][j-arr[i]];
                dp[i][j]=take||nottake;
            }
        }
        return dp[arr.size()-1][sum];
    }
};


//space optimised
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<int> dp(sum+1,0);
        vector<int> temp(sum+1,0);
        dp[0]=temp[0]=1;
        if(arr[0]<=sum)dp[arr[0]]=1;
        for(int i=1;i<arr.size();i++){
            for(int j=1;j<=sum;j++){
                int nottake=dp[j];
                int take=0;
                if(j>=arr[i])take=dp[j-arr[i]];
                temp[j]=take||nottake;
            }
            dp=temp;
        }
        return dp[sum];
    }