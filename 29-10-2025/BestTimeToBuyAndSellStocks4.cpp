#include<bits/stdc++.h>
using namespace std;
//recursion
class Solution {
private:
    int helper(int ind, int cntTrans, int k, vector<int> &prices, vector<vector<int>> &dp){
        if(ind==prices.size() || cntTrans==k*2)return 0;
        if(dp[ind][cntTrans]!=-1)return dp[ind][cntTrans];
        int ans=0;
        if(cntTrans%2==0){
            int p=helper(ind+1, cntTrans+1, k, prices, dp)-prices[ind];//buy
            int np=helper(ind+1, cntTrans, k, prices, dp);//skip
            ans=max({ans,p,np});
        }
        else if(cntTrans%2==1){
            int p=prices[ind]+helper(ind+1,cntTrans+1, k, prices, dp);//sell
            int np=helper(ind+1, cntTrans, k, prices, dp);//skip
            ans=max({ans,p,np});
        }
        return dp[ind][cntTrans]=ans;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(k*2, -1));
        return helper(0,0, k, prices, dp);
    }
};

//tabulation
int maximumProfit(vector<int> &prices, int n, int k)
{
   vector<vector<int>> dp(prices.size()+1, vector<int>(k*2+1, 0));
   for(int i=prices.size()-1;i>=0;i--){
       for(int j=0;j<2*k;j++){
            int ans=0;
            if(j%2==0){
                int f=0;
                int p=dp[i+1][j+1]-prices[i];//buy
                int np=dp[i+1][j];//skip
                f=max(p,np);
                ans=max(ans,f);
            }
            else if(j%2==1){
                int f=0;
                int p=prices[i]+dp[i+1][j+1];//sell
                int np=dp[i+1][j];//skip
                f=max(p,np);
                ans=max(ans,f);
            }
            dp[i][j]=ans;
       }
   }
   return dp[0][0];
}


//space optimization
int stockBuySell(vector<int> &arr) {
    int n=arr.size();
    vector<long long> dp(2,0);
    for(int i=n-1;i>=0;i--){
        vector<long long> temp(2);
        for(int j=0;j<2;j++){
            long ans=0;
            if(j==1){
                ans=max(dp[0]-arr[i], dp[1]);
            }else{
                ans=max(dp[1]+arr[i], dp[0]);
            }
            temp[j]=ans;
        }
        dp=temp;
    }
    return dp[1];
}