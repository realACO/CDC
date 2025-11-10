#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        vector<pair<int,int>> MST;
        
        vector<int> visited(V,0);
        int s=0;
        priority_queue<tuple<int,int,int>, 
        vector<tuple<int,int,int>>, 
        greater<tuple<int,int,int>>> q;
        q.push({0,0,-1});
        
        while(!q.empty()){
            auto t=q.top();
            q.pop();
            int d=get<0>(t);
            int n=get<1>(t);
            int p=get<2>(t);
            if(visited[n])continue;//dont need the already visited nodes
            s+=d;//sum of the nodes that have minimmum distance and not visited
            MST.push_back({p,n});
            visited[n]=1;
            
            for(auto i:adj[n]){
                if(!visited[i.first]){
                    q.push({i.second,i.first,n});
                }
            }
            
        }
        MST.erase(MST.begin());
        for(auto i:MST){
            cout<<i.first<<" "<<i.second<<endl;
        }
        return s;
    }
};