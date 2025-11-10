#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int bfs(int i, int j, int time, vector<vector<int>> &grid,
         vector<vector<int>> &visited, vector<int> &dr, vector<int> &dc)
    {
        int n = grid.size();

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
        q.push({grid[i][j],i, j});
        visited[i][j] = 1;
        while(!q.empty()) {
            auto t = q.top();
            int x=get<0>(t);
            int y=get<1>(t);
            int z=get<2>(t);
            q.pop();
            if(y == n - 1 && z == n - 1)
                return true;

            for(int k = 0; k < 4; k++){
                int r = y + dr[k];
                int c = z + dc[k];

                if(r >= 0 && r < n && c >= 0 && c < n &&
                   !visited[r][c] && grid[r][c] <= time) {

                    visited[r][c] = 1;
                    q.push({grid[r][c],r, c});
                }
            }
        }

        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        int n=grid.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxi=max(maxi,grid[i][j]);
            }
        }
        int ans=-1;
        int s=0;
        int e=maxi;
        while(s<=e){
            vector<vector<int>> visited(n,vector<int>(n,0));
            int m=s+(e-s)/2;
            if(grid[0][0]<=m && bfs(0,0,m,grid,visited,dr,dc)){
                ans=m;
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return ans;
    }
};