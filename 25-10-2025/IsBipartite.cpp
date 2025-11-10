#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//for loop is for graph with multiple components
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> visited(n,-1);
        //-1 means not visited
        // 1,0 are other colors
        queue<int> q;
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                visited[i]=0;
                q.push(i);
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(int j:adj[x]){
                        if(visited[j]==-1){
                            q.push(j);
                            visited[j]=!visited[x];
                        }
                        else if(visited[j]==visited[x])return false;
                    }
                }
            }
        }


        return true;
    }
};


//using dfs
class Solution {
private:
    bool dfs(int ind,vector<vector<int>>& adj,vector<int> &visited){
        for(int i:adj[ind]){
            if(visited[i]==-1){
                visited[i]=!visited[ind];
                if(!dfs(i,adj,visited))return false;//if at any point of the recursive cll it returns false the ans is false
                //so only recurse if its true if it returns false then no need to move on
            }
            else if(visited[i]==visited[ind])return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> visited(n,-1);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                visited[i]=0;
                if(!dfs(i,adj,visited))return false;
            }
        }
        return true;
    }
};