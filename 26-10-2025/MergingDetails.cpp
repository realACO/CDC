//merging details gfg
#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
  
    int findParent(int n, vector<int> &p){
        if(n==p[n])return n;
        return p[n]=findParent(p[n],p);
    }
    
    void Union(int a,int b,vector<int> &p, vector<int> &s){
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
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        int n=details.size();
        unordered_map<string,int> m;
        
        vector<int> s(n,1);
        vector<int> p(n);
        for(int i=0;i<n;i++)p[i]=i;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<details[i].size();j++){
                if(m.find(details[i][j])==m.end()){
                    m[details[i][j]]=i;
                }
                else{
                    Union(i,m[details[i][j]],p,s);
                }
            }
        }
        
        vector<string> ans[n];
        for(auto i:m){
            int a=findParent(i.second,p);
            ans[a].push_back(i.first);
        }
        
        vector<vector<string>> res;
        for(int i=0;i<n;i++){
            if(ans[i].size()==0)continue;
            sort(ans[i].begin(),ans[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for(auto j:ans[i]){
                temp.push_back(j);
            }
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//accounts merge gfg
// User function Template for C++

class Solution {
  private:
    int findParent(int n, vector<int> &p){
        if(n==p[n])return n;
        return p[n]=findParent(p[n],p);
    }
    
    void Union(int a,int b, vector<int> &p, vector<int> &s){
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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n=accounts.size();
        vector<int> p(n);
        for(int i=0;i<n;i++)p[i]=i;
        vector<int> s(n,1);
        
        unordered_map<string,int> m;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j])==m.end()){
                    m[accounts[i][j]]=i;
                }else{
                    Union(i,m[accounts[i][j]],p,s);
                }
            }
        }
        
        vector<string> res[n];
        for(auto i:m){
            int a=findParent(i.second,p);
            res[a].push_back(i.first);
        }
        
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(res[i].size()==0)continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(res[i].begin(),res[i].end());
            for(auto j:res[i]){
                temp.push_back(j);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
