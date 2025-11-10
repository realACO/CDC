#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }

        queue<tuple<int,int,int>> q;
        q.push({0,src,0});
        dist[src]=0;
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int stops=get<0>(t);
            int node=get<1>(t);
            int d=get<2>(t);
            if(stops>k)continue;
            for(auto i:adj[node]){
                if(d+i.second<dist[i.first]){
                    dist[i.first]=d+i.second;
                    q.push({stops+1,i.first,d+i.second});
                }
            }
        }

        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX)dist[i]=-1;
        }

        return dist[dst];
    }
};