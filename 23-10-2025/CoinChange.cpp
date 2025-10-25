#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        //bottom up 1d dp
        for(int i=1;i<dp.size();i++){//iterated through all possible amounts
            for(int j:coins){//for an particular amount go through each denomination of coins
                if(i-j>=0){//if the difference between amount and that coin is greater than equal to 0 
                    //then we update the dp[i] with min of dp[i] and dp[i-j]+1
                    //+1 is for the current coin and dp[i-j] stores the amount of coin required to make up the remaining amount
                    //example dp[7] stores the amount of coins requires to get amount 7
                    //if coins are 1,3,4
                    //dp[7]=min(dp[7],1+dp[7-1])
                    //dp[7]=min(dp[7],1+dp[7-3])
                    //dp[7]=min(dp[7],1+dp[7-4])
                    dp[i]=min(dp[i],dp[i-j]+1);
                }
            }
        }
        if(dp[amount]>amount)return -1;
        return dp[amount];
    }
};