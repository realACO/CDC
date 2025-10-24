#include<bits/stdc++.h>
using namespace std;
//leetcode
class Solution {
public:
    bool possible(int r,int c,int n,vector<string> &a){
        for(int i=c;i>=0;i--){
            if(a[r][i]=='Q')return false;//check if there are no queens already in a row
        }

        //check for diagonal up
        int dur=r-1;
        int duc=c-1;
        while(dur>=0&&duc>=0){
            if(a[dur][duc]=='Q')return false;
            dur--;
            duc--;
        }

        //check for diagonal down
        int ddr=r+1;
        int ddc=c-1;
        while(ddr<n&&ddc>=0){
            if(a[ddr][ddc]=='Q')return false;
            ddr++;
            ddc--;
        }
        return true;
    }
    void solve(int c,int n,vector<vector<string>> &ans,vector<string> &a){//recursive backtracking function to place the queens
        if(c==n){
            ans.push_back(a);//push a into ans once the no of columns reach n
            return;
        }

        //i here act as rows, for columns we have c
        for(int i=0;i<a.size();i++){
            if(possible(i,c,n,a)){//check if it is pooible to place the queen
                a[i][c]='Q';//place the queen
                solve(c+1,n,ans,a);//recurse the function
                a[i][c]='.';//backtrack back
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {//this function initializes ans,a
        vector<string> a(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(0,n,ans,a);
        return ans;
    }
};


//gfg
class Solution {
  public:
    bool possible(int r,int c,int n,vector<int> &a){
        for(int i=0;i<r;i++){
            if(a[i]==c||abs(a[i]-c)==abs(i-r))return false;
            //abs(a[i]-c)==abs(i-r) diagonal check
            //a[i]==c horizontal check
        }
        return true;
    }
    void solve(int r,int n,vector<vector<int>> &ans,vector<int> &a){
        if(n==r){
            ans.push_back(a);
            return;
        }
        for(int i=1;i<=n;i++){
            if(possible(r,i,n,a)){
                a.push_back(i);
                solve(r+1,n,ans,a);
                a.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<int> a;
        vector<vector<int>> ans;
        solve(0,n,ans,a);
        return ans;
    }
};