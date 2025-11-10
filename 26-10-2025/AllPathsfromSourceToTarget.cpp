#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int n,vector<int> path, vector<vector<int>> &paths,vector<vector<int>> &graph){
        path.push_back(n);
        if(n==graph.size()-1){
            paths.push_back(path);
        }else{
            for(auto i:graph[n]){
                dfs(i,path,paths,graph);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> paths;
        dfs(0,path,paths,graph);
        return paths;
    }
};