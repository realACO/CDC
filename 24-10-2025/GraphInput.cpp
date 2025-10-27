#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>> adj(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    
    vector<vector<int>> adjlist(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //for undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
        
        //for directed graph u-->v
        adj[u].push_back(v);
    }
}