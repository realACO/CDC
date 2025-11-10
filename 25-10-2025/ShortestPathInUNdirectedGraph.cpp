#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V=adj.size();
        vector<int> dist(V,INT_MAX);
        
        queue<pair<int,int>> q;
        q.push({src,0});
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int a=t.first;
            int b=t.second;
            dist[a]=min(b,dist[a]);
            for(int i:adj[a]){
                if(dist[i]>b+1){
                    q.push({i,b+1});
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX)dist[i]=-1;
        }
        return dist;
    }
};