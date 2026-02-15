#include<bits/stdc++.h>
using namespace std;
int longestBitonicSubsequence(vector<int>& arr, int n)
{

	vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }

    reverse(arr.begin(),arr.end());
	vector<int> dp1(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp1[i]=max(dp1[i],1+dp1[j]);
            }
        }
    }
    reverse(arr.begin(), arr.end());
    reverse(dp1.begin(),dp1.end());
    int ans=max(dp[n-1],dp1[0]);
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i]+dp1[i]-1);
    }
    
    return ans;
}
