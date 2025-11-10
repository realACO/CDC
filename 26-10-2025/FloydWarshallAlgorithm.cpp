#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n=dist.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(dist[j][i]!=1e8 && dist[i][k]!=1e8){
                        dist[j][k]=min(dist[j][k],(dist[j][i]+dist[i][k]));
                    }
                }
            }
        }
    }
};