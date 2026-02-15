#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int helper(int ind, int canbuy, vector<int> &prices, vector<vector<int>> &dp){
        if(ind>=prices.size())return 0;
        int ans=0;
        if(dp[ind][canbuy]!=-1)return dp[ind][canbuy];
        if(canbuy){
            int p=helper(ind+1, 0, prices, dp)-prices[ind];//buy
            int np=helper(ind+1, 1, prices, dp);//skip
            ans=max({ans,p,np});
        }
        else{
            int p=prices[ind]+helper(ind+2,1, prices, dp);//sell and consider the cooldown
            int np=helper(ind+1, 0, prices, dp);//skip
            ans=max({ans,p,np});
        }
        return dp[ind][canbuy]=ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return helper(0,1,prices,dp);
    }
};


//tabulation
int stockProfit(vector<int> &prices){
    vector<vector<int>> dp(prices.size()+2,vector<int>(2,0));
    for(int i=prices.size()-1;i>=0;i--){
        for(int j=0;j<2;j++){
            int ans=0;
            if(j==1){
                int p=dp[i+1][0]-prices[i];
                int np=dp[i+1][1];
                ans=max({ans,p,np});
            }else{
                int p=prices[i]+dp[i+2][1];
                int np=dp[i+1][0];
                ans=max({ans,p,np});
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][1];
}


//ultimateee space optimizatiiiiionnnnn
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+2,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;i--){
            dp[i][1]=max(dp[i+1][0]-prices[i],dp[i+1][1]);
            dp[i][0]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
        }
        return dp[0][1];
    }
};