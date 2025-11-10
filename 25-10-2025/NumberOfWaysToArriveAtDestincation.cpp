//leetcode
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }

        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        dist[0]=0;
        ways[0]=1;

        priority_queue<pair<long long,int>, vector<pair<long long,int>> ,greater<pair<long long,int>>> q;
        q.push({0,0});

        int mod=(int)(1e9+7);
        while(!q.empty()){
            auto t=q.top();
            int node=t.second;
            long long d=t.first;
            q.pop();
            if(d>dist[node])continue;
            for(auto i:adj[node]){
                if((i.second+d)<dist[i.first]){
                    dist[i.first]=(i.second+d);
                    q.push({dist[i.first],i.first});
                    ways[i.first]=ways[node]%mod;
                }
                else if(i.second+d==dist[i.first]){
                    ways[i.first]=(ways[i.first]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

//gfg
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,0});
        
        int mod=(int)(1e9+7);
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        vector<int> ways(n,0);
        ways[0]=1;
        while(!q.empty()){
            auto t=q.top();
            int d=t.first;
            int node=t.second;
            q.pop();
            if(d>dist[node])continue;
            for(auto i:adj[node]){
                if(d+i.second<dist[i.first] ){
                    dist[i.first]=i.second+d;
                    q.push({dist[i.first],i.first});
                    ways[i.first]=ways[node];
                }
                else if(d+i.second==dist[i.first]){
                    ways[i.first]=(ways[i.first]+ways[node])%mod;
                }
            }
        }
        // for(int i:ways)cout<<i<<" ";
        return ways[n-1]%mod;
    }
};