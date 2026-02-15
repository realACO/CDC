#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    long long helper(int i, int j,  vector<int> &arr, vector<vector<int>> &dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<=j;k++){
            int s=(arr[j+1]-arr[i-1])+helper(i,k-1,arr,dp)+helper(k+1,j,arr,dp);
            mini=min(mini,s);
        }
        return dp[i][j]=mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),-1));
        return helper(1,cuts.size()-2,cuts,dp);
    }
};



//tabulation
int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),0));
    for(int i=c;i>=1;i--){
        for(int j=i;j<=c;j++){
            int mini=INT_MAX;
            for(int k=i;k<=j;k++){
                int s=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                mini=min(mini,s);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][cuts.size()-2];
}

//1833
//979
//1233
//1992
//2125