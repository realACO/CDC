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
        }
        else{
            p[u]=v;
            s[v]+=s[u];
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> p(n);
        for(int i=0;i<p.size();i++)p[i]=i;

        vector<int> s(n,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    Union(i,j,p,s);
                }
            }
        }
        for(int i=0;i<n;i++){
            p[i]=findParent(i,p);
        }
        unordered_set<int> st(p.begin(),p.end());
        return st.size();
    }
};