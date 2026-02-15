#include<bits/stdc++.h>
using namespace std;
int helper(int ind, int n, vector<int> &price,vector<vector<int>> &dp){
	if(ind==0){
		if(n>=1)return price[ind]*(n);
		return 0;
	}
	if(dp[ind][n]!=-1)return dp[ind][n];
	int p=0;
	if((ind+1)<=n)p=price[ind]+helper(ind,n-(ind+1),price,dp);
	int np=helper(ind-1, n, price, dp);
	return dp[ind][n]=max(p,np);
}
int cutRod(vector<int> &price, int n)
{
    vector<int> dp(n+1,0);
    for(int i=0;i<=n;i++){
        dp[i]=price[0]*i;
    }
    for(int i=1;i<price.size();i++){
        for(int j=0;j<=n;j++){
            int np=dp[j];
            int p=0;
            if(j>=(i+1))p=price[i]+dp[j-i-1];
            dp[j]=max(p,np);
        }
    }
    return dp[price.size()];
}
