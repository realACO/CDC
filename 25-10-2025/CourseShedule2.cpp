#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses);
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
            indeg[i[1]]++;
        }

        vector<int> ans;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!indeg[i])q.push(i);
        }

        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(int i:adj[x]){
                indeg[i]--;
                if(!indeg[i])q.push(i);
            }
        }

        reverse(ans.begin(),ans.end());
        if(ans.size()!=numCourses)return {};
        return ans;
    }
};