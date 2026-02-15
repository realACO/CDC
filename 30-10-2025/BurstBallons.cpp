#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int helper(int i, int j, vector<int> &nums,vector<vector<int>> &dp){
        if(j<i)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j;k++){
            int s=(nums[i-1]*nums[k]*nums[j+1])+helper(i,k-1,nums,dp)+helper(k+1,j,nums,dp);
            ans=max(ans,s);
        }
        return dp[i][j]=ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return helper(1,n,nums,dp);
    }
};


//tabulation
int burstBalloons(vector<int> &arr){
    int n=arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(),1);
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(i>j)continue;
            int maxi=INT_MIN;
            for(int k=i;k<=j;k++){
                int s=arr[i-1]*arr[j+1]*arr[k]+dp[i][k-1]+dp[k+1][j];
                maxi=max(maxi,s);
            }
            dp[i][j]=maxi;
        }
    }
    return dp[1][n];
}