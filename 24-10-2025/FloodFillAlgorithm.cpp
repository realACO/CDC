//using dfs on gfg

#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>& visited,
    int element,int newColor){
        int n=image.size();
        int m=image[0].size();
        visited[row][col]=1;
        image[row][col]=newColor;
        if(row+1<n && image[row+1][col]==element && visited[row+1][col]==0){
            dfs(row+1,col,image,visited,element,newColor);
        }
        if(row-1>=0 && image[row-1][col]==element && visited[row-1][col]==0){
            dfs(row-1,col,image,visited,element,newColor);
        }
        if(col+1<m && image[row][col+1]==element && visited[row][col+1]==0){
            dfs(row,col+1,image,visited,element,newColor);
        }
        if(col-1>=0 && image[row][col-1]==element && visited[row][col-1]==0){
            dfs(row,col-1,image,visited,element,newColor);
        }
    }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int n=image.size();
        int m=image[0].size();
        int element=image[sr][sc];
        vector<vector<int>> visited(n,vector<int>(m,0));
        dfs(sr,sc,image,visited,element,newColor);
        return image;
    }
};

//using bfs on leetcode
#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    void bfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>& visited,
    int element,int newColor){
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int a=t.first;
            int b=t.second;
            visited[a][b]=1;
            image[a][b]=newColor;
            if(a+1<n && image[a+1][b]==element && visited[a+1][b]==0){
                q.push({a+1,b});
                visited[a+1][b]=1;
                image[a+1][b]=newColor;
            }
            if(a-1>=0 && image[a-1][b]==element && visited[a-1][b]==0){
                q.push({a-1,b});
                visited[a-1][b]=1;
                image[a-1][b]=newColor;
            }
            if(b+1<m && image[a][b+1]==element && visited[a][b+1]==0){
                q.push({a,b+1});
                visited[a][b+1]=1;
                image[a][b+1]=newColor;
            }
            if(b-1>=0 && image[a][b-1]==element && visited[a][b-1]==0){
                q.push({a,b-1});
                visited[a][b-1]=1;
                image[a][b-1]=newColor;
            }
        }

    }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int n=image.size();
        int m=image[0].size();
        int element=image[sr][sc];
        vector<vector<int>> visited(n,vector<int>(m,0));
        bfs(sr,sc,image,visited,element,newColor);
        return image;
    }
};