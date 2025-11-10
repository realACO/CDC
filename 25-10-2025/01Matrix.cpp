#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<int> rd={0,-1,0,1};
        vector<int> cd={-1,0,1,0};

        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> ans=visited;

        queue<tuple<int,int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    visited[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            auto t=q.front();
            int row=get<0>(t);
            int col=get<1>(t);
            int cost=get<2>(t);
            q.pop();
            ans[row][col]=cost;
            visited[row][col]=1;
            for(int k=0;k<4;k++){
                int rr=row+rd[k];
                int cc=col+cd[k];
                if(rr<n && rr>=0 && cc<m && cc>=0 && mat[rr][cc]==1 && visited[rr][cc]==0){
                    q.push({rr,cc,cost+1});
                    visited[rr][cc]=1;
                }
            }
        }
        return ans;
    }
};


//distance of nearest cell having 1
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        vector<int> dr={0,-1,0,1};
        vector<int> dc={-1,0,1,0};
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> ans=visited;
        
        queue<tuple<int,int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j,0});
                    visited[i][j]=1;
                }
            }
        }
        
        while(!q.empty()){
            auto [a,b,c]=q.front();
            q.pop();
            ans[a][b]=c;
            visited[a][b]=1;
            for(int k=0;k<4;k++){
                int rr=a+dr[k];
                int cc=b+dc[k];
                if(rr<n && rr>=0 && cc<m && cc>=0 && visited[rr][cc]==0 && grid[rr][cc]==0){
                    q.push({rr,cc,c+1});
                    visited[rr][cc]=1;
                }
            }
        }
        
        return ans;
    }
