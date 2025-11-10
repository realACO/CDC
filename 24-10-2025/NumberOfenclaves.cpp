// using dfs
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(int i,int j,vector<int> &dr,vector<int> &dc, vector<vector<int>>& grid,vector<vector<int>>& visited,int &c){
        int n=grid.size();
        int m=grid[0].size();

        c++;
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int rr=i+dr[k];
            int cc=j+dc[k];
            if(rr+1<n && rr-1>=0 && cc+1<m && cc-1>=0 && !visited[rr][cc] && grid[rr][cc]==1)dfs(rr,cc,dr,dc,grid,visited,c);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<int> dr={0,-1,0,1};
        vector<int> dc={-1,0,1,0};

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));

        int c=0;
        int tc=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)tc++;
                if(grid[i][j]==1 && (i+1>=n || i-1<0 || j+1>=m || j-1<0) && !visited[i][j]){
                    dfs(i,j,dr,dc,grid,visited,c);
                }
            }
        }

        return tc-c;
    }
};

//using bfs
class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> dr={0,-1,0,1};
        vector<int> dc={-1,0,1,0};
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        int tc=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)tc++;
                if(grid[i][j]==1 && (i==n-1 || i==0 || j==m-1 || j==0)){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        
        while(!q.empty()){
            auto [a,b]=q.front();
            visited[a][b]=1;
            q.pop();
            for(int i=0;i<4;i++){
                int rr=a+dr[i];
                int cc=b+dc[i];
                if((rr<n && rr>=0 && cc<m &&cc>=0) && !visited[rr][cc] && grid[rr][cc]==1){
                    q.push({rr,cc});
                }
            }
        }
        
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==1)c++;
            }
        }
        return tc-c;
        
    } 
};
