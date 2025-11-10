#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    void dfs(bool push, int n, vector<vector<int>> &adj, vector<int> &visited, stack<int> &s){
        visited[n]+=1;
        for(auto i:adj[n]){
            if(!visited[i]){
                dfs(push,i,adj,visited,s);
            }
        }
        if(push)s.push(n);
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<int> visited(n,0);
        stack<int> s;
        for(int i=0;i<n;i++){
            if(!visited[i])dfs(true, i,adj,visited,s);
        }
        
        
        vector<vector<int>> RevAdj(n);
        for(int i=0;i<n;i++){
            for(int j:adj[i]){
                RevAdj[j].push_back(i);
            }
        }
        
        int c=0;
        vector<int> NewVisited(n,0);
        while(!s.empty()){
            int a=s.top();
            s.pop();
            if(!NewVisited[a]){
                c++;
                dfs(false,a,RevAdj,NewVisited,s);
            }
        }
        
        return c;
    }
};