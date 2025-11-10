#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> grid(n,vector<int>(n,1e9));
        for(auto i:edges){
            grid[i[0]][i[1]]=i[2];
            grid[i[1]][i[0]]=i[2];
        }
        for(int i=0;i<n;i++)grid[i][i]=0;
        for(int i=0;i<n;i++)grid[i][i]=0;

        int ans=INT_MAX;
        int res;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(grid[j][i]==INT_MAX && grid[i][k]==INT_MAX)continue;
                    grid[j][k]=min(grid[j][k],grid[j][i]+grid[i][k]);
                }
            }
        }

        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]<=distanceThreshold && i!=j)c++;
            }
            if(c<=ans){
                ans=c;
                res=i;
            }
        }

        return res;
    }
};