//0 based indexing
#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    bool bfs(int ind,vector<vector<int>> &adj,vector<int> &visited){
        visited[ind]=1;
        queue<pair<int,int>> q;
        q.push({ind,-1});
        while(!q.empty()){
            auto t=q.front();
            int a=t.first;
            int b=t.second;
            q.pop();
            for(int i:adj[a]){
                if(!visited[i]){
                    q.push({i,a});
                    visited[i]=1;
                }
                else if(i!=b && visited[i]==1)return true;
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
                if(bfs(i,adj,visited))return true;
            }
        }
        return false;
    }
};

//1 based indexing
#include<bits/stdc++.h>
bool bfs(vector<vector<int>> &adj, vector<int> &visited, int ind){
    visited[ind]=1;
    queue<pair<int,int>> q;
    q.push({ind,-1});
    while(!q.empty()){
        auto t=q.front();
        int a=t.first;
        int b=t.second;
        visited[a]=1;
        q.pop();
        visited[a]=1;
        for(int j:adj[a]){
            if(!visited[j]){
                q.push({j,a});
                visited[j]=1;
            }
            else if(j!=b && visited[j]==1)return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n+1);
    for(auto i:edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    
    vector<int> visited(n+1,0);
    visited[0]=1;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(bfs(adj,visited,i))return "Yes";
        }
    }
    return "No";
}
