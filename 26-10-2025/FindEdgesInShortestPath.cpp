#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> dijkstras(int n, int src, vector<vector<pair<int,int>>>& adj){
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,src});
        while(!q.empty()){
            auto t=q.top();
            q.pop();
            int d=t.first;
            int nn=t.second;
            if(d>dist[nn])continue;
            for(auto i:adj[nn]){
                if(d+i.second<dist[i.first]){
                    dist[i.first]=d+i.second;
                    q.push({dist[i.first],i.first});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX)dist[i]=-1;
        }
        return dist;
    }
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int> dist0=dijkstras(n,0,adj);
        vector<int> distN=dijkstras(n,n-1,adj);

        int mini=dist0[n-1];
        vector<bool> ans;
        for(auto i:edges){

            if((dist0[i[0]]!=-1 && distN[i[1]]!=-1 && mini==(dist0[i[0]]+distN[i[1]]+i[2]))|| 
            (dist0[i[1]]!=-1 && distN[i[0]]!=-1 && mini==(dist0[i[1]]+distN[i[0]]+i[2]))){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
//dijkstras from 0 to all nodes
//dijkstras from last node to all node


//for a node u->v
//if the min possible dist in a mst i.e dist to 0 to reach end is equal to 
//weight of u->v + dist to reach from 0 to u and dist to reach from end to v 
//weight of u->v + dist to reach from end to u and dist to reach from 0 to v 
//then that edges is a part of valid mst