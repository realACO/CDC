#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto i:edges){
            int a=i.first;
            int b=i.second;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        return adj;
    }
};