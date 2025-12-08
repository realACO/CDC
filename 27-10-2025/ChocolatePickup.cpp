#include <bits/stdc++.h> 
using namespace std;
//memoization
int helper(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    int n=grid.size();
    int m=grid[0].size();
    if(j1<0 || j2<0 || j1>m-1 || j2>m-1){
        return -1e8;
    }
    if(i==n-1){
        if(j1==j2){
            return grid[i][j1];
        }
        return grid[i][j1]+grid[i][j2];
    } 
    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }
    int ans=INT_MIN;
    for(int k=-1;k<=1;k++){
        int r=j1+k;
        for(int j=-1;j<=1;j++){
            int rr=j2+j;
            if(j1==j2)ans=max(ans,grid[i][j1]+helper(i+1,r,rr,grid,dp));
            else{
                ans=max(ans,grid[i][j1]+grid[i][j2]+helper(i+1,r,rr,grid,dp));
            }
        }
    }
    return dp[i][j1][j2]=ans;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    return helper(0,0,c-1,grid,dp);
}



//tabulation
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m)));
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2){
                dp[n-1][j1][j2]=grid[n-1][j1];
            }else{
                dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int ans=INT_MIN;
                for(int k=-1;k<=1;k++){
                    int r=j1+k;
                    for(int j=-1;j<=1;j++){
                        int value=0;
                        int rr=j2+j;
                        if(j1==j2)value=grid[i][j1];
                        else{
                            value=grid[i][j1]+grid[i][j2];
                        }
                        if(r>=0 && rr>=0 && r<m && rr<m){
                            value+=dp[i+1][r][rr];
                        }else{
                            value=-1e9;
                        }
                        ans=max(value,ans);
                    }
                }
                dp[i][j1][j2]=ans;
            }
        }
    }
    return dp[0][0][m-1];
}


//space optimization
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<int>> dp(m,vector<int>(m));
    vector<vector<int>> temp(m,vector<int>(m));
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2){
                dp[j1][j2]=grid[n-1][j1];
            }else{
                dp[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int ans=INT_MIN;
                for(int k=-1;k<=1;k++){
                    int r=j1+k;
                    for(int j=-1;j<=1;j++){
                        int value=0;
                        int rr=j2+j;
                        if(j1==j2)value=grid[i][j1];
                        else{
                            value=grid[i][j1]+grid[i][j2];
                        }
                        if(r>=0 && rr>=0 && r<m && rr<m){
                            value+=dp[r][rr];
                        }else{
                            value=-1e9;
                        }
                        ans=max(value,ans);
                    }
                }
                temp[j1][j2]=ans;
            }
        }
        dp=temp;
    }
    return dp[0][m-1];
}

