#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        
        vector<int> dist(V,INT_MAX);
        
        q.push({0,src});
        dist[src]=0;
        while(!q.empty()){
            
            auto t=q.top();
            int w=t.first;
            int n=t.second;
            
            q.pop();
            for(auto i:adj[n]){
                if(w+i.second<dist[i.first]){ 
                    dist[i.first]=w+i.second;
                    q.push({w+i.second,i.first});
                }
            }
        }
        
        return dist;
    }
};


//using set
// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        set<pair<int,int>> s;
        
        vector<int> dist(V,INT_MAX);
        
        s.insert({0,src});
        dist[src]=0;
        
        while(!s.empty()){
            auto t=*s.begin();//value at start of the set s
            int n=t.second;
            int w=t.first;
            s.erase(t);
            for(auto i:adj[n]){
                if(w+i.second<dist[i.first]){
                    if(dist[i.first]!=INT_MAX){
                        s.erase({dist[i.first],i.first});//remove larger pairfron the set completly
                    }
                    dist[i.first]=w+i.second;
                    s.insert({dist[i.first],i.first});
                }
            }
        }
        
        return dist;
    }
};