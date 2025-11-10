#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank,parent,size;
    public:
        //constructor that initializes the arrays rank and parent with its default values
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            parent.resize(n+1,1);
            for(int i=0;i<n+1;i++){
                parent[i]=i;
            }
        }
        
        //recursive funtction that finda the ultimate parent of a node
        int find(int n){
            if(n==parent[n])return n;
            return parent[n]=find(parent[n]);
        }
        
        void UnionByRank(int u, int v){
            int pu=find(u);
            int pv=find(v);
            if(pu=pv)return;
            if(rank[pu]>rank[pv])parent[pv]=pu;
            else if(rank[pu]<rank[pv])parent[pu]=pv;
            else if(rank[pu]==rank[pv]){
                parent[pu]=pv;
                rank[pu]++;
            }
        }
        
        void UnionBySize(int u, int v){
            int pu=find(u);
            int pv=find(v);
            if(pu=pv)return;
            if(size[pu]<size[pv]){
                parent[pu]=pv;
                size[pv]+=size[pu];
            }else{
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
        }
};