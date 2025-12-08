#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> dp=grid[n-1];
        for(int i=n-2;i>=0;i--){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                int mini=INT_MAX;
                for(int k=0;k<n;k++){
                    if(k==j)continue;
                    mini=min(mini,dp[k]);
                }
                temp[j]=grid[i][j]+mini;
            }
            dp=temp;
        }
        int ans=INT_MAX;
        for(int i:dp){
            ans=min(ans,i);
        }
        return ans;
    }
};