#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};

        vector<vector<int>> visited(n,vector<int>(m,0));

        int perimeter=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=1;
                    break;
                }
            }
        }
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int r=t.first+dr[k];
                int c=t.second+dc[k];
                if(r<0 || r>=n || c<0 || c>=m){
                    perimeter++;
                    continue;
                }
                else if(grid[r][c]==0)perimeter++;
                else if(grid[r][c]==1 && !visited[r][c]){
                    q.push({r,c});
                    visited[r][c]=1;
                }
            }
        }
        return perimeter;
    }
};