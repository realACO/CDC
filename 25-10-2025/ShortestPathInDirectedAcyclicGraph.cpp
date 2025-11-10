// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(V);
        vector<int> indegree(V,0);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            indegree[i[1]]++;
        }
        
        vector<int> topo;
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(!indegree[i])q.push(i);
        }
        
        while(!q.empty()){
            int x=q.front();
            topo.push_back(x);
            q.pop();
            for(auto i:adj[x]){
                indegree[i.first]--;
                if(!indegree[i.first])q.push(i.first);
            }
        }
        
        
        vector<int> minD(V,INT_MAX);
        minD[0]=0;
        for(int i=0;i<topo.size();i++){
            int n=topo[i];
            for(auto j:adj[n]){
                int v=j.first;
                int d=j.second;
                if(minD[n]!=INT_MAX && minD[n]+d<minD[v]){
                    minD[v]=minD[n]+d;
                }
            }
        }
        for(int i=0;i<minD.size();i++){
            if(minD[i]==INT_MAX)minD[i]=-1;
        }
        return minD;
    }
};
