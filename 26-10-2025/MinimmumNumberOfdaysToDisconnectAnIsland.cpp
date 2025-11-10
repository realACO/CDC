#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited){
        int n=grid.size();
        int m=grid[0].size();
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int r=i+dr[k];
            int c=j+dc[k];
            if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 && !visited[r][c]){
                dfs(r,c,grid,visited);
            }
        }
    }
    int numberOfIslads(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    ans++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return ans;
    }

public:
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int a=numberOfIslads(grid);
        if(a==0 || a>1)return 0;

        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)c++;
            }
        }
        if(c==1)return 1;
        
        int ans=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(numberOfIslads(grid)>1)return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};