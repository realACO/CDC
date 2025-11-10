#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    bool dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &visited){
        visited[node]=1;
        for(int i:adj[node]){
            if(!visited[i]){
                if(dfs(i,node,adj,visited))return true;
            }
            else if(visited[i] && i!=parent){
                return true;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,-1,adj,visited))return true;
            }
        }
        return false;
    }
};