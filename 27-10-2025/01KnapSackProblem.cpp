#include <bits/stdc++.h> 
using namespace std;
//recursion + memoization
class Solution {
  private:
    int helper(int ind, int W, vector<int> &val, vector<int> &wt,vector<vector<int>> &dp){
        if(ind==0){
            if(W>=wt[0])return val[0];
            return 0;
        }
        if(dp[ind][W]!=-1)return dp[ind][W];
        int p=0;
        if(W>=wt[ind])p=helper(ind-1,W-wt[ind],val,wt,dp) + val[ind];
        int np=helper(ind-1,W,val,wt,dp);
        return dp[ind][W]=max(p,np);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(val.size(),vector<int>(W+1,-1));
        return helper(val.size()-1,W,val,wt,dp);
    }
};

//tabulation code
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
	for(int i=weight[0];i<=maxWeight;i++){
		dp[0][i]=value[0];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<=maxWeight;j++){
			int p=INT_MIN;
			if(weight[i]<=j)p=dp[i-1][j-weight[i]]+value[i];
			int np=dp[i-1][j];
			dp[i][j]=max(p,np);
		}
	}
	return dp[n-1][maxWeight];
}


//space optimisation
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> dp(maxWeight+1);
	for(int i=weight[0];i<=maxWeight;i++){
		dp[i]=value[0];
	}
	for(int i=1;i<n;i++){
		vector<int> temp(maxWeight+1);
		for(int j=0;j<=maxWeight;j++){
			int p=INT_MIN;
			if(weight[i]<=j)p=dp[j-weight[i]]+value[i];
			int np=dp[j];
			temp[j]=max(p,np);
		}
		dp=temp;
	}
	return dp[maxWeight];
}


//more space optimised
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> dp(maxWeight+1);
	for(int i=weight[0];i<=maxWeight;i++){
		dp[i]=value[0];
	}
	for(int i=1;i<n;i++){
		for(int j=maxWeight;j>=0;j--){
			int p=INT_MIN;
			if(weight[i]<=j)p=dp[j-weight[i]]+value[i];
			int np=dp[j];
			dp[j]=max(p,np);
		}
	}
	return dp[maxWeight];
}