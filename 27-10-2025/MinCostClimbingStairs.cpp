#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int minCost(int ind, vector<int> &cost,vector<int> &dp){
        if(ind>=cost.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int x=cost[ind]+minCost(ind+1,cost,dp);
        int y=cost[ind]+minCost(ind+2,cost,dp);
        return dp[ind]=min(x,y);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        vector<int> dp1(cost.size(),-1);
        return min(minCost(0,cost,dp),minCost(1,cost,dp1));
    }
};




class Solution {
public:
    int minCost(int ind, vector<int> &cost,vector<int> &dp){
        if(ind<=1){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int x=cost[ind-1]+minCost(ind-1,cost,dp);
        int y=cost[ind-2]+minCost(ind-2,cost,dp);
        return dp[ind]=min(x,y);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return minCost(cost.size(),cost,dp);
    }
};




class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        dp[0]=dp[1]=0;
        for(int i=2;i<cost.size()+1;i++){
            int p=cost[i-1]+dp[i-1];
            int np=cost[i-2]+dp[i-2];
            dp[i]=min(p,np);
        }
        return dp[cost.size()];
    }
};