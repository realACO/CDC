//
//normal recursion
#include <bits/stdc++.h>
using namespace std;
int helper(int i,int i1, int j1, int j2, vector<vector<int>> &grid){
    int n=grid.size();
    int m=grid[0].size();
    if(j1<0 || j2<0 || j1>=m || j2>=m || i>=n || i1>=n){
        return 0;
    }
    if(grid[i][j1]==-1 || grid[i1][j2]==-1){
        return -1e9;
    }
    if(i==n-1 && j1==m-1 && j2==m-2){
        return grid[i][j1];
    }
    int val=-1e9;
    if(j1==j2){
        val=grid[i][j1];
    }else{
        val=grid[i][j1]+grid[i1][j2];
    }
    int ans=0;
    ans=max(ans,val+helper(i+1,i1+1,j1,j2,grid));
    ans=max(ans,val+helper(i,i1,j1+1,j2+1,grid));
    ans=max(ans,val+helper(i,i1+1,j1+1,j2,grid));
    ans=max(ans,val+helper(i+1,i1,j1,j2+1,grid));
    return ans;
}
int cherryPickup(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    return helper(0,0,0,0,grid);
}


//3d dp replaces i1 with i+j1-j2 bcs i+j1=i1+j2
#include <bits/stdc++.h>
int helper(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    int n=grid.size();
    int m=grid[0].size();
    if(j1<0 || j2<0 || j1>=m || j2>=m || i>=n || i+j1-j2>=n){
        return 0;
    }
    if(grid[i][j1]==-1 || grid[i+j1-j2][j2]==-1){
        return -1e9;
    }
    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }
    if(i==n-1 && j1==m-1 && j2==m-2){
        return grid[i][j1];
    }
    int val=-1e9;
    if(j1==j2){
        val=grid[i][j1];
    }else{
        val=grid[i][j1]+grid[i+j1-j2][j2];
    }
    int ans=0;
    ans=max(ans,val+helper(i+1,j1,j2,grid,dp));
    ans=max(ans,val+helper(i,j1+1,j2+1,grid,dp));
    ans=max(ans,val+helper(i,j1+1,j2,grid,dp));
    ans=max(ans,val+helper(i+1,j1,j2+1,grid,dp));
    return dp[i][j1][j2]=ans;
}
int cherryPickup(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    return helper(0,0,0,grid,dp);
}