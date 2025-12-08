#include <bits/stdc++.h> 
using namespace std;
//recursive
class Solution {
private:
    int sequence(int ind, int sum, int target, vector<int> &nums,vector<vector<int>> &dp){
        if(sum==target)return 1;
        if(sum>target)return 0;
        if(ind>=nums.size())return 0;
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        int p=sequence(ind+1,sum+nums[ind],target,nums,dp);
        int np=sequence(ind+1,sum,target,nums,dp);
        return dp[ind][sum]=(p||np);
    }
public:
    bool canPartition(vector<int>& nums) {
        int t=0;
        for(int i:nums)t+=i;
        vector<vector<int>> dp(nums.size()+1,vector<int>(t/2+1,-1)); 
        if(t%2==1)return false;
        return sequence(0,0,t/2,nums,dp);
    }
};


//tabulation
bool canPartition(vector<int> &arr, int n)
{
	int sum=0;
	for(auto i:arr)sum+=i;
	if(sum%2==1)return false;
	sum/=2;

	vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1,0));
	for(int i=0;i<arr.size();i++){
		dp[i][0]=1;
	}

	if(arr[0]<=sum){
		dp[0][arr[0]]=1;
	}

	for(int i=1;i<arr.size();i++){
		for(int j=1;j<=sum;j++){
			int p=dp[i-1][j];
			int np=0;
			if(j>=arr[i])np=dp[i-1][j-arr[i]];
			dp[i][j]=p||np;
		}
	}
	return dp[arr.size()-1][sum];
}
