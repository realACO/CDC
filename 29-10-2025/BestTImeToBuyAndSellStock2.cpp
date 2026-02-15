#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int helper(int ind, bool buy, vector<int> &nums, vector<vector<int>> &dp){
        if(ind==nums.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int ans=0;
        if(buy){
            int f=0;
            int p=helper(ind+1,false, nums,dp) + (-1*nums[ind]);
            int np=helper(ind+1,true, nums,dp);
            f=max(p,np);
            ans=max(ans,f);
        }else{
            int f=0;
            int p=helper(ind+1,true, nums, dp) + (nums[ind]);
            int np=helper(ind+1,false, nums, dp);
            f=max(p,np);
            ans=max(ans,f);
        }
        return dp[ind][buy]=ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1)); 
        return helper(0,true, prices,dp);
    }
};


class Solution {
  public:
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
};



int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int zero=0;
    int one=0;
    for(int i=n-1;i>=0;i--){
        int tempzero;
        int tempone;
        for(int j=0;j<2;j++){
            long ans=0;
            if(j==1){
                tempone=max(zero-prices[i], one);
            }else{
                tempzero=max(one+prices[i], zero);
            }
        }
        zero=tempzero;
        one=tempone;
    }
    return one;
}
