//gfg only horizontal and vertical movement allowed
#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
                         
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> 
        q;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        
        dist[source.first][source.second]=0;
        
        q.push({0,source});
        
        while(!q.empty()){
            auto t=q.top();
            int d=t.first;
            auto node=t.second;
            q.pop();
            
            for(int k=0;k<4;k++){
                
                int rr=node.first+dr[k];
                int cc=node.second+dc[k];
                
                if(rr>=0 && rr<n && cc>=0 && cc<m && grid[rr][cc]==1
                && (dist[node.first][node.second]+1)<dist[rr][cc] ){
                    dist[rr][cc]=d+1;
                    q.push({dist[rr][cc],{rr,cc}});
                }
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dist[i][j]==INT_MAX){
                    dist[i][j]=-1;
                }
            }
        }
        return dist[destination.first][destination.second];
    }
};


//leetcode movement in all 8 directions allowed and aloso in the question we have to move through 0 and not 1 like the gfg codr
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<int> dr={0,-1,-1,-1,0,1,1,1};
        vector<int> dc={-1,-1,0,1,1,1,0,-1};
        if(grid[0][0]==1)return -1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=!grid[i][j];
            }
        }

        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> q;
        q.push({1,{0,0}});
        dist[0][0]=1;

        while(!q.empty()){
            auto t=q.top();
            q.pop();

            int d=t.first;
            auto node=t.second;
            int r=node.first;
            int c=node.second;

            for(int k=0;k<8;k++){
                int rr=r+dr[k];
                int cc=c+dc[k];
                if(rr>=0 && rr<n && cc>=0 && cc<n && grid[rr][cc]==1 && dist[r][c]+grid[rr][cc]<dist[rr][cc]){
                    dist[rr][cc]=d+grid[rr][cc];
                    q.push({dist[rr][cc],{rr,cc}});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]==INT_MAX){
                    dist[i][j]=-1;
                }
            }
        }

        return dist[n-1][n-1];
    }
};