#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& visited){
        int n=grid.size();
        int m=grid[0].size();
        vector<int> dr={1,0,-1,0};
        vector<int> dc={0,1,0,-1};


        queue<tuple<int,int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                    visited[i][j]=1;
                }
            }
        }

        int maxi=0;
        while(!q.empty()){
            auto t=q.front();
            visited[get<0>(t)][get<1>(t)]=1;
            maxi=get<2>(t);
            q.pop();
            for(int i=0;i<4;i++){
                int r=get<0>(t)+dr[i];
                int c=get<1>(t)+dc[i];
                if(r>=0 && r<n && c>=0 && c<m && visited[r][c]==0 && grid[r][c]==1){
                    q.push({r,c,get<2>(t)+1});
                    visited[r][c]=1;
                    grid[r][c]=2;
                }
            }
        }
        return maxi;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int ans= bfs(grid,visited);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return ans;
    }
};