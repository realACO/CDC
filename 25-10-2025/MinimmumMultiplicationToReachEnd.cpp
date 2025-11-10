#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        vector<int> dist(100000,INT_MAX);
        q.push({start,0});
        dist[start]=0;
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int node=t.first;
            int steps=t.second;
            for(int i:arr){
                int nn=i*node%100000;
                if(dist[nn]>steps+1){
                    dist[nn]=steps+1;
                    q.push({nn,steps+1});
                }
            }
        }
        
        if(dist[end]==INT_MAX)return -1;
        return dist[end];
    }
};
