#include<bits/stdc++.h>
using namespace std;
int findNumberOfLIS(vector<int> &arr)
{
    int n=arr.size();
    vector<int> dp(n,1);
    vector<int> cnt(n,1);
    int maxi=0;
    int s=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                if(dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];
                }else if(1+dp[j]==dp[i]){
                    cnt[i]+=cnt[j];
                }
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi){
            ans+=cnt[i];
        }
    }
    return ans;
}