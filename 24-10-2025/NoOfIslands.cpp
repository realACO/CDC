#include<bits/stdc++.h>
using namespace std;
//gfg wla
//litle tough one where the land can be connected from all eight sides
class Solution {
  private:
  //apply dfs, akso can apply bfs
    void dfs(int row,int col, vector<vector<int>> &v,vector<vector<char>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        v[row][col]=1;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int r= row+i;
                int c=col+j;
                if(r>=0&&c>=0&&r<n&&c<m&&v[r][c]==0&&grid[r][c]=='L'){
                    dfs(r,c,v,grid);
                }
            }
        }
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==0&&grid[i][j]=='L'){
                    ans++;
                    dfs(i,j,v,grid);
                }
            }
        }
        return ans;
    }
};


//easier question on leetcode
class Solution {
private:
    void bfs(int row,int col,vector<vector<int>> &v,vector<vector<char>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        v[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            pair<int,int> t=q.front();
            q.pop();
            int a=t.first;
            int b=t.second;
            if(a-1>=0 && v[a-1][b]==-1 && grid[a-1][b]=='1'){
                q.push({a-1,b});
                v[a-1][b]=1;
            }
            if(b-1>=0 && v[a][b-1]==-1 && grid[a][b-1]=='1'){
                q.push({a,b-1});
                v[a][b-1]=1;
            }
            if(a+1<n && v[a+1][b]==-1 && grid[a+1][b]=='1'){
                q.push({a+1,b});
                v[a+1][b]=1;
            }
            if(b+1<m && v[a][b+1]==-1 && grid[a][b+1]=='1'){
                q.push({a,b+1});
                v[a][b+1]=1;
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> v(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==-1 && grid[i][j]=='1'){
                    ans++;
                    bfs(i,j,v,grid);
                }
            }
        }
        return ans;
    }
};

//steps
//make a visited array of size m*n and initialize it with 0
//run through each elemnt of grid and call dfs/bfs when land is encountered and its also unvisited
//the dfs/bfs will make sure all the connected land with it is also marked visited in the visited vector
//do when the no of times our call goes for the bfs/dfs is the no of islands we have