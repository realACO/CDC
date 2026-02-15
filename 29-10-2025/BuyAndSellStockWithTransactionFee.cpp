#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int helper(int ind, int tf, bool CntTrans, vector<int> &prices, vector<vector<int>> &dp){
        if(ind==prices.size())return 0;
        if(dp[ind][CntTrans]!=-1)return dp[ind][CntTrans];
        int ans=0;
        if(CntTrans==0){
            ans=max({ans, helper(ind+1,tf,1,prices,dp)-prices[ind],  helper(ind+1,tf,0,prices,dp)});
        }else{
            ans=max({ans, helper(ind+1,tf,0,prices,dp)+prices[ind]-tf,  helper(ind+1,tf,1,prices,dp)});
        }
        return dp[ind][CntTrans]=ans;
    }
//tabulation
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int ans=0;
                if(j==0){
                    ans=max({ans,dp[i+1][1]-prices[i], dp[i+1][0]});
                }else{
                    ans=max({ans, dp[i+1][0]+prices[i]-fee,  dp[i+1][1]});
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
};



//most optimal
class Solution {
  public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        for(int i=prices.size()-1;i>=0;i--){
            int ans=0;
            dp[i][0]=max({ans,dp[i+1][1]-prices[i], dp[i+1][0]});
            dp[i][1]=max({ans, dp[i+1][0]+prices[i]-fee,  dp[i+1][1]});
        }
        return dp[0][0];
    }
};