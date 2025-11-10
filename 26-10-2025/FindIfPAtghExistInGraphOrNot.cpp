#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        vector<int> visited(n,0);
        q.push(source);
        while(!q.empty()){
            auto t=q.front();
            visited[t]=1;
            q.pop();
            if(t==destination)return true;
            for(int i:adj[t]){
                if(!visited[i])q.push(i);
            }
        } 
        return false;
    }
};