#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(vector<vector<int>> &adj) {
    vector<int> ans;
    vector<int> visited(adj.size(),0);
    visited[0]=1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        ans.push_back(t);
        vector<int> a=adj[t];
        for(int i:a){
            if(visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }
    return ans;
}
int main(){

}