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
        int v=findParent(b,p);if(u==v)return;
        if(s[u]>s[v]){
            p[v]=u;
            s[u]+=s[v];
        }else{
            p[u]=v;
            s[v]+=s[u];
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int r=0;
        int c=0;
        for(auto i:stones){
            r=max(r,i[0]);
            c=max(c,i[1]);
        }

        vector<int> p(r+c+2);
        for(int i=0;i<r+c+2;i++)p[i]=i;
        vector<int> s(r+c+2,1);

        set<int> st;
        for(auto i:stones){
            Union(i[0],r+i[1]+1,p,s);
            st.insert(i[0]);
            st.insert(r+i[1]+1);
        }

        int count=0;
        for(int i:st){
            if(i==findParent(i,p))count++;
        }
        return stones.size()-count;
    }
};