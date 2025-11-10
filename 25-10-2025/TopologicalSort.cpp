//using bfs
#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    void dfs(int ind, vector<vector<int>> &adj,vector<int> &visited, stack<int> &s){
        visited[ind]=1;
        for(int i:adj[ind]){
            if(!visited[i]){
                dfs(i,adj,visited,s);
            }
        }
        s.push(ind);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
        }
        vector<int> visited(V,0);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,s);
            }
        }
        
        vector<int> ans;
        while(!s.empty()){
            int x=s.top();
            s.pop();
            ans.push_back(x);
        }
        return ans;
    }
};

//using dfs/ khans algo
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        
        vector<int> ans;
        vector<int> visited(V,0);
        queue<int> q;
        for(int i=0;i<V;i++){
            if(!indegree[i]){
                visited[i]=1;
                q.push(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(int i:adj[x]){
                indegree[i]--;
                if(!indegree[i]){
                    q.push(i);
                }
            }
        }

        return ans;
    }
};




//topo sort to detect cycle ina directed graph
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        vector<int> indeg(V,0);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            indeg[i[1]]++;
        }
        
        int c=0;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(!indeg[i]){
                q.push(i);
                c++;
            }
        }
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i:adj[x]){
                indeg[i]--;
                if(indeg[i]==0){
                    q.push(i);
                    c++;
                }
            }
        }
        
        return c!=V;//size of topo sort should be equal to the no of nodes and if its not then we have a cycle graph to deal with
    }
};