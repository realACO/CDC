#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> dist(n+1,INT_MAX);
        vector<int> parent(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
        q.push({0,1});
        dist[1]=0;
        
        while(!q.empty()){
            auto t=q.top();
            q.pop();
            int node=t.second;
            int d=t.first;
            
            for(auto i:adj[node]){
                if(d+i.second<dist[i.first]){
                    dist[i.first]=d+i.second;
                    q.push({dist[i.first],i.first});
                    parent[i.first]=node;
                }
            }
        }
        if(dist[n]==INT_MAX)return {-1};
        
        vector<int> path;
        int l=n;
        while(l!=1){
            path.push_back(l);
            l=parent[l];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        path.insert(path.begin(),dist[n]);
        return path;
        
    }
};