#include<bits/stdc++.h>
using namespace std;
//dfs directly on adjacency matrix
class Solution {
public:
    void dfs(int ind,vector<vector<int>>& mat,vector<int> &visited){
        visited[ind]=1;
        for(int i=0;i<mat.size();i++){
            if(!visited[i]&&mat[ind][i]==1){
                dfs(i,mat,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        vector<int> visited(isConnected.size(),0);
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                ans++;
                dfs(i,isConnected,visited);
            }
        }
        return ans;
    }
};



//converting adjacency matrix to adjacency lisyt then aplying dfs
// User function Template for C++

class Solution {
  public:
    void dfs(int ind,vector<vector<int>> &adj,vector<int> &visited){
        visited[ind]=1;
        for(int i:adj[ind]){
            if(!visited[i]){
                dfs(i,adj,visited);
            }
        }
    }
    int numProvinces(vector<vector<int>> mat, int V) {
        vector<vector<int>> adj(mat.size(),vector<int>(0));
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(mat[i][j]==1&&i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> visited(adj.size(),0);
        int ans=0;
        for(int i=0;i<visited.size();i++){
            if(visited[i]==0){
                ans++;
                dfs(i,adj,visited);
            }
        }
        return ans;
    }
};

//converting matric into adjacency list and doin bfs
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size(),vector<int>(0));
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1&&i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<int> visited(isConnected.size(),0);
        for(int k=0;k<visited.size();k++){//traverse visited one by one
            //if not visited then increment ans and call dfs/ bfs on that node
            if(!visited[k]){
                ans++;
                queue<int> q;
                q.push(k);
                while(!q.empty()){
                    int t=q.front();
                    q.pop();
                    for(int i:adj[t]){
                        if(!visited[i]){
                            visited[i]=1;
                            q.push(i);
                        }
                    }
                }
            }
        }
        return ans;
    }
};