#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int findParent(int n,vector<int> &p){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> p(n);
        for(int i=0;i<n;i++)p[i]=i;

        vector<int> s(n,1);

        int c=0;
        for(auto i:connections){
            if(findParent(i[0],p)==findParent(i[1],p))c++;
            if(findParent(i[0],p)!=findParent(i[1],p)){
                Union(i[0],i[1],p,s);
            }
        }
        int comp=-1;
        for(int i=0;i<n;i++){
            if(p[i]==i)comp++;
        }
        cout<<comp<<" "<<c;
        if(c<comp)return -1;
        return comp;

    }
};