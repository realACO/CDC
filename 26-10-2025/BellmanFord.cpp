#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V,1e8);
        dist[src]=0;
        for(int j=0;j<V-1;j++){
            for(auto i:edges){
                if(dist[i[0]]!=1e8 && dist[i[0]]+i[2]<dist[i[1]]){
                    dist[i[1]]=dist[i[0]]+i[2];
                }
            }
        }
        for(auto i:edges){
            if(dist[i[0]]!=1e8 && dist[i[0]]+i[2]<dist[i[1]]){
                return {-1};
            }
        }
        
        return dist;
    }
};
