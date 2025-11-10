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
            p[v]=u;;
            s[u]+=s[v];
        }else{
            p[u]=v;;
            s[v]+=s[u];
        }
    }
public:
    int MaxConnection(vector<vector<int>>& grid) {
        vector<int> dr={-1,0,1,0};
	    vector<int> dc={0,-1,0,1};

        int n=grid.size();
        vector<int> p(n*n);
        for(int i=0;i<n*n;i++)p[i]=i;
        vector<int> s(n*n,1);
        vector<int> visited(n*n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int ind=i*n+j;
                if(grid[i][j]==1 && !visited[ind]){
                    visited[ind]=1;
                    for(int k=0;k<4;k++){
                        int r=i+dr[k];
                        int c=j+dc[k];
                        int nn=r*n+c;
                        if(r>=0 && r<n && c>=0 &&c<n && !visited[nn] && grid[r][c]==1){
                            Union(nn,ind,p,s);
                        }
                    }
                }
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int> par;
                    for(int k=0;k<4;k++){
                        int r=i+dr[k];
                        int c=j+dc[k];
                        int nn=r*n+c;
                        if(r>=0 && r<n && c>=0 &&c<n && grid[r][c]==1){
                            int a=findParent(nn,p);
                            par.insert(a);
                        }
                    }
                    int sum=1;
                    for(auto i:par)sum+=s[i];
                    ans=max(ans,sum);
                }
            }
        }
        if(ans==-1 && grid[0][0]==1)return n*n;
        return ans;
    }
};