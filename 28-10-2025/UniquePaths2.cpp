#include<bits/stdc++.h>
using namespace std;

//tabulation 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1)continue;
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                int up=0;
                int left=0;
                if(i>0 && obstacleGrid[i-1][j]!=1)up=dp[i-1][j];
                if(j>0 && obstacleGrid[i][j-1]!=1)left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        return dp[n-1][m-1];
    }
};

//tabulation +space optimisation
class Solution {
  public:
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        if(m==1 && n==1 &&grid[0][0]==1)return 0;
        if(m==1 && n==1 &&grid[0][0]==0)return 1;
        int mod=1e9+7;
        vector<long long> dp(m,0);
        for(int i=0;i<n;i++){
            vector<long long> temp(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    temp[j]=1;
                    continue;
                }
                if(grid[i][j]==1){
                    temp[j]=0;
                    continue;
                }
                int up=dp[j]%mod;
                int left=0;
                if(j>0)left=temp[j-1]%mod;
                temp[j]=(up+left)%mod;
            }
            dp=temp;
        }
        return dp[m-1]%mod;
    }
};