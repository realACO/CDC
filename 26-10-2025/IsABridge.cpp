#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
  
    int findParent(int n, vector<int> &p){
        if(n==p[n])return n;
        return p[n]=findParent(p[n],p);
    }
    
    void Union(int a, int b, vector<int> &p, vector<int> &s){
        int u=findParent(a,p);
        int v=findParent(b,p);
        if(u==v)return;
        if(s[u]>s[v]){
            p[v]=u;
            s[u]+=s[v];
        }else{
            p[u]=v;
            s[v]+=s[u];
        }
    }
    
  public:
    bool isBridge(int n, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> adj(n);
        
        vector<int> p(n);
        for(int i=0;i<n;i++){
            p[i]=i;
        }
        vector<int> s(n,1);
        
        for(auto i:edges){
            if(i[0]==c && i[1]==d)continue;
            if(i[1]==c && i[0]==d)continue;
            Union(i[0],i[1],p,s);
        }
        
        int a=findParent(c,p);
        int b=findParent(d,p);
        // cout<<a<<" "<<b<<endl;
        if(a==b)return false;
        return true;
        
    } 
};