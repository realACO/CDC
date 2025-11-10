#include<bits/stdc++.h>
using namespace std;
int findParent(int n, vector<int> &p){
	if(n==p[n])return n;
	return p[n]=findParent(p[n],p);
}
void Union(int a,int b, vector<int> &p ,vector<int> &s){
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
vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	vector<int> p(n*m);
	for(int i=0;i<n*m;i++)p[i]=i;
	vector<int> s(n*m,1);

	vector<int> dr={-1,0,1,0};
	vector<int> dc={0,-1,0,1};

	vector<int> ans;

	vector<vector<int>> visited(n,vector<int>(m,0));

	int co=0;
	for(auto i:q){
		int ind=i[0]*m+i[1];
		if(visited[i[0]][i[1]]){
			ans.push_back(co);
			continue;
		}
		visited[i[0]][i[1]]=1;
		co++;
		for(int k=0;k<4;k++){
			int r=i[0]+dr[k];
			int c=i[1]+dc[k];
			int nn=r*m+c;
			if(r>=0 && r<n && c>=0 && c<m && visited[r][c]){
				if(findParent(nn,p)!=findParent(ind,p)){
					Union(nn,ind,p,s);
					co--;
				}
			}
		}
		ans.push_back(co);
	}
	return ans;
}