#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//do bfs on the O's that are not surrounded by X fully map O to a dummy matrix filled with X
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<char>> v(n,vector<char>(m,'X'));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i+1>=n||i-1<0||j+1>=m||j-1<0) && board[i][j]=='O'){
                    q.push({i,j});
                }
            }
        } 
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int a=t.first;
            int b=t.second;
            v[a][b]='O';
            if(a-1>=0 && board[a-1][b]=='O' && v[a-1][b]=='X'){
                q.push({a-1,b});
            }
            if(a+1<n && board[a+1][b]=='O' && v[a+1][b]=='X'){
                q.push({a+1,b});
            }
            if(b-1>=0 && board[a][b-1]=='O' && v[a][b-1]=='X'){
                q.push({a,b-1});
            }
            if(b+1<m && board[a][b+1]=='O' && v[a][b+1]=='X'){
                q.push({a,b+1});
            }
        }
        board=v;
    }
};