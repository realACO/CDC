// i implemented this using priority queue but you can do it just by sorting edges
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findparent(vector<int> &p, int n){
        if(p[n]==n)return n;
        return p[n]=findparent(p,p[n]);
    }
    
    void Union(int a, int b, vector<int> &p, vector<int> &size){
        int pa=findparent(p,a);
        int pb=findparent(p,b);
        if(pa==pb)return;
        if(size[pa]>size[pb]){
            p[pb]=pa;
            size[pa]+=size[pb];
        }else{
            p[pa]=pb;
            size[pb]+=size[pa];
        }
    }
    
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        
        vector<int> parent(V);
        for(int i=0;i<V;i++)parent[i]=i;
        
        vector<int> size(V,1);
        
        vector<pair<int,int>> MST;
        int s=0;
        
        priority_queue<tuple<int,int,int>, 
        vector<tuple<int,int,int>>, 
        greater<tuple<int,int,int>>> q;
        
        for(auto i:edges){
            q.push({i[2],i[0],i[1]});
        }
        
        int i=1;
        while(!q.empty() && i<V){
            auto t=q.top();
            int d=get<0>(t);
            int u=get<1>(t);
            int v=get<2>(t);
            q.pop();
            int a=findparent(parent,u);
            int b=findparent(parent,v);
            if(a!=b){
                MST.push_back({u,v});
                i++;
                s+=d;
                Union(u,v,parent,size);
            }
        }
        return s;
    }
};



//without the queue
// User function Template for C++
class Solution {
  public:
    int findparent(vector<int> &p, int n){
        if(p[n]==n)return n;
        return p[n]=findparent(p,p[n]);
    }
    
    void Union(int a, int b, vector<int> &p, vector<int> &size){
        int pa=findparent(p,a);
        int pb=findparent(p,b);
        if(pa==pb)return;
        if(size[pa]>size[pb]){
            p[pb]=pa;
            size[pa]+=size[pb];
        }else{
            p[pa]=pb;
            size[pb]+=size[pa];
        }
    }
    
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        
        vector<int> parent(V);
        for(int i=0;i<V;i++)parent[i]=i;
        
        vector<int> size(V,1);
        
        vector<pair<int,int>> MST;
        int s=0;
        
        vector<tuple<int,int,int>> q;
        for(auto i:edges){
            q.push_back({i[2],i[0],i[1]});
        }
        sort(q.begin(),q.end());
        
        for(auto t:q){
            int d=get<0>(t);
            int u=get<1>(t);
            int v=get<2>(t);
            int a=findparent(parent,u);
            int b=findparent(parent,v);
            if(a!=b){
                MST.push_back({u,v});
                s+=d;
                Union(u,v,parent,size);
            }
        }
        return s;
    }
};