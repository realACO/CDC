//leetocde
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        
        int n=heights.size();
        int m=heights[0].size(); 

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        dist[0][0]=0;
        while(!q.empty()){
            auto t=q.top();
            int d=t.first;
            auto y=t.second;
            q.pop();

            for(int k=0;k<4;k++){
                int rr=y.first+dr[k];
                int cc=y.second+dc[k];
                if(rr>=0 && rr<n &&cc>=0 &&cc<m){
                    int e= max(d,abs(heights[rr][cc]-heights[y.first][y.second]));
                    if(e<dist[rr][cc]){
                        dist[rr][cc]=e;
                        q.push({dist[rr][cc],{rr,cc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};

//gfg

class Solution {
  public:
    int MinimumEffort(int n, int m, vector<vector<int>> &heights) {
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> ,
        greater<pair<int,pair<int,int>>>> q;
        
        q.push({0,{0,0}});
        dist[0][0]=0;
        while(!q.empty()){
            auto t=q.top();
            q.pop();
            int d=t.first;
            auto node=t.second;
            for(int k=0;k<4;k++){
                int rr=node.first+dr[k];
                int cc=node.second+dc[k];
                if(rr>=0 && rr<n && cc>=0 && cc<m){
                    int e=max(d,abs(heights[rr][cc]-heights[node.first][node.second]));
                    if(e<dist[rr][cc]){
                        dist[rr][cc]=e;
                        q.push({dist[rr][cc],{rr,cc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};
