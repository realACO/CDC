#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    bool dfs(int ind, vector<vector<int>> &adj, vector<int> &visited, vector<int> &path, vector<int> &count){
        visited[ind]=1;
        path[ind]=1;
        for(int i:adj[ind]){
            if(visited[i]&&path[i])return false;
            if(!visited[i]){
                if(!dfs(i,adj,visited,path,count))return false;//set false to all the members of the cycle 
            }
        }
        path[ind]=0;
        count[ind]=1;//no cycle detected to set count and return true
        return true;
    }
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
        }
        
        vector<int> visited(V,0);
        vector<int> path(V,0);
        
        vector<int> ans;
        vector<int> safe;
        
        vector<int> count(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,path,count);//run dfs for ech node ans if it does not encounter a cycle set corresponding count index to 1
            }
        }
        for(int i=0;i<V;i++){
            if(count[i]==1)safe.push_back(i);
        }
        return safe;
    }
};

//using topological sort
//sort the toplogical sort array and return it
class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indeg(V,0);
        for(auto i:edges){
            adj[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }
        vector<int>ans;
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(!indeg[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            ans.push_back(x);
            q.pop();
            for(int i:adj[x]){
                indeg[i]--;
                if(!indeg[i])q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};