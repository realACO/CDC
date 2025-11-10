#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//bfs from each water source
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<int> dr={0,-1,0,1};
        vector<int> dc={-1,0,1,0};

        int n=isWater.size();
        int m=isWater[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> ans=visited;
        queue<tuple<int,int,int>> q;//{row,col,cost}

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({i,j,0});
                    visited[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            auto t=q.front();
            int row=get<0>(t);
            int col=get<1>(t);
            int cost=get<2>(t);
            q.pop();
            ans[row][col]=cost;
            visited[row][col]=1;
            cout<<cost<<endl;
            for(int k=0;k<4;k++){
                int rr=row+dr[k];
                int cc=col+dc[k];
                if(rr<n && rr>=0 && cc<m && cc>=0 && visited[rr][cc]==0 && isWater[rr][cc]==0){
                    q.push({rr,cc,cost+1});
                    visited[rr][cc]=1;
                }
            }
        }

        return ans;
    }
};