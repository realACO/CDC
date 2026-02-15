#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int helper(int n, vector<int>& nums, int prev, vector<vector<int>>& dp){
        if(n==nums.size())return 0;
        if(dp[n][prev+1]!=-1)return dp[n][prev+1];
        int p=0;
        if(prev==-1 || nums[prev]<nums[n])p=1+helper(n+1,nums,n,dp);
        int np=helper(n+1,nums,prev,dp);
        return dp[n][prev+1]=max(p,np);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int p=0;
                if(j==-1||nums[j]<nums[i])p=1+dp[i+1][i+1];
                int np=dp[i+1][j+1];
                dp[i][j+1]=max(p,np);
            }
        }
        return dp[0][-1+1];
    }
};


//optimal code nlogn
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>ans.back())ans.push_back(arr[i]);
        else{
            int it=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[it]=arr[i];
        }
    }
    return ans.size();
}