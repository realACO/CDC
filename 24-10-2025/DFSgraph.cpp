#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int ind,vector<int> &visited,vector<vector<int>>& adj,vector<int> &ans){
        //this function pushes the ind to ans and taverse through adjacent list of ind and recurse the dfs function again if the element inadjacency list is not visited
        visited[ind]=1;
        ans.push_back(ind);
        for(int i:adj[ind]){
            if(!visited[i]){
                dfs(i,visited,adj,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> visited(adj.size(),0);
        visited[0]=1;
        vector<int> ans;
        dfs(0,visited,adj,ans);
        return ans;
    }
};