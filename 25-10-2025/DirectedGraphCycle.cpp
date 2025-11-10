#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    bool dfs(int ind,vector<int> &visited,vector<int> &path,vector<vector<int>> &adj){
        visited[ind]=1;
        path[ind]=1;
        for(int i:adj[ind]){
            if(visited[i]&&path[i]){//return trueonly when node is visitd and its also included in the path
                return true;
            }
            if(dfs(i,visited,path,adj))return true;
        }
        path[ind]=0;//when we come back fron the function we reset path to 0, to track other paths
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
        }
        
        vector<int> visited(V,0);
        vector<int> path(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,visited,path,adj))return true;
            }
        }
        return false;
    }
};