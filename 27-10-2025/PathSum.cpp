#include<bits/stdc++.h>
using namespace std;
//tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        int t=0;
        for(int i=0;i<n;i++){
            t+=grid[i][0];
            dp[i][0]=t;
        }
        t=0;
        for(int i=0;i<m;i++){
            t+=grid[0][i];
            dp[0][i]=t;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};

//optimised tabulation
#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<int> dp(m,0);
    for(int i=0;i<n;i++){
        vector<int> temp(m);
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                temp[0]=grid[0][0];
                continue;
            }
            int u=dp[j];
            int l=0;
            if(j>0){
                l+=temp[j-1];
            }
            if(j==0){
                temp[j]=u+grid[i][j];
                continue;
            }
            if(i==0){
                temp[j]=l+grid[i][j];
                continue;
            }
            temp[j]=min(u,l)+grid[i][j];
        }
        dp=temp;
    }
    return dp[m-1];
}