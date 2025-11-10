#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int find(int par[], int n){
        if(n==par[n])return n;
        return par[n]=find(par,par[n]);
    }
    void union_(int a, int b, int par[], int rank[]) {
        int pa=find(par,a);
        int pb=find(par,b);
        if(pa==pb)return;
        if(rank[pa]>rank[pb])par[pb]=pa;
        else if(rank[pb]>rank[pa])par[pa]=pb;
        else if(rank[pa]==rank[pb]){
            par[pa]=pb;
            rank[pb]++;
        }
    }
    bool isConnected(int x, int y, int par[], int rank[]) {
        return find(par,x)==find(par,y);
    }
};