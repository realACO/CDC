#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool possible(vector<vector<char>>& b,int r,int c,char t){
        for(int i=0;i<9;i++){
            if(b[i][c]==t)return false;
            if(b[r][i]==t)return false;
            if(b[3*(r/3)+i/3][3*(c/3)+i%3]==t)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& b){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(b[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(possible(b,i,j,c)){
                            b[i][j]=c;
                            if(solve(b)){
                                return true;
                            }else{
                                b[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};