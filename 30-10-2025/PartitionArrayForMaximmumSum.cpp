#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int helper(int i, int k, vector<int> &arr, vector<int> &dp){
        if(i>=arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MIN;
        int partMaxi=arr[i];
        for(int ind=i;ind<i+k && ind<arr.size();ind++){
            partMaxi=max(partMaxi,arr[ind]);
            int t=partMaxi*(ind-i+1)+helper(ind+1,k,arr,dp);
            ans=max(ans,t);
        }
        return dp[i]=ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(arr.size(),-1);
        return helper(0,k,arr,dp);
    }
};


//tabulation
#include<bits/stdc++.h>
using namespace std;
int maximumSubarray(vector<int> &arr, int k){
    int n=arr.size();
    vector<int> dp(n+1,0);
    for(int i=n-1;i>=0;i--){
        int ans=0;
        int partMaxi=arr[i];
        for(int j=i;j<i+k && j<n;j++){
            partMaxi=max(partMaxi,arr[j]);
            int t=partMaxi*(j-i+1)+dp[j+1];
            ans=max(ans,t);
        }
        dp[i]=ans;
    }
    return dp[0];
}