#include<bits/stdc++.h>
using namespace std;
int find(int parent[], int n) {
    if(n==parent[n])return n;
    return find(parent,parent[n]);
}

void unionSet(int par[], int u, int v) {
    int pu=find(par,u);
    int pv=find(par,v);
    par[pu]=pv;
}