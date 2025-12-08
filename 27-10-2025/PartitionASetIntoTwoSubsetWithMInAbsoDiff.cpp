#include <bits/stdc++.h> 
using namespace std;
int minSubsetSumDifference(vector<int>& nums, int n)
{
	int t=0;
    for(int i:nums)t+=i;
    vector<vector<int>> dp(nums.size(),vector<int>(t+1,0));
    for(int i=0;i<nums.size();i++)dp[i][0]=1;
    if(nums[0]<=t)dp[0][nums[0]]=1;
    for(int i=1;i<nums.size();i++){
        for(int j=1;j<=t;j++){
            int p=dp[i-1][j];
            int np=0;
            if(nums[i]<=j)np=dp[i-1][j-nums[i]];
            dp[i][j]=p||np;
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<=t;i++){
        if(dp[nums.size()-1][i]){
            ans=min(ans,abs(t-2*i));
        }
    }
    return ans;
}
