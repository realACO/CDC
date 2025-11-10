//using floyd warshal
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> dist(n+1,vector<int>(n+1,1e9));
        for(auto i:times){
            dist[i[0]][i[1]]=i[2];
        }

        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                for(int k=0;k<n+1;k++){
                    if(dist[j][i]==INT_MAX && dist[i][k]==INT_MAX)continue;
                    dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                }
            }
        }
        int d=INT_MIN;
        for(int i=1;i<n+1;i++){
            if(i==k)continue;
            if(dist[k][i]==1e9)return -1;
            d=max(dist[k][i],d);
        }
        return d;
    }
};

//using dikastras
class Solution {
  public:
    int findDelayTime(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> q;
        q.push({0,src});
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        while(!q.empty()){
            auto t=q.top();
            q.pop();
            int d=t.first;
            int n=t.second;
            for(auto i:adj[n]){
                if(d+i.second<dist[i.first]){
                    dist[i.first]=d+i.second;
                    q.push({dist[i.first],i.first});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX)return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
        
    }
};