#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string findOrder(vector<string> &words) {
        vector<vector<char>> edges;
        unordered_map<char,set<char>> adj;
        unordered_map<char,int> indegree;
        for(auto i:words){
            for(char c:i){
                indegree[c];
            }
        }
        
        for(int i=0;i<words.size()-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int j=0;
            int k=0;
            while(j<s1.size() && k<s2.size()){
                if(s1[j]!=s2[k]){
                    edges.push_back({s1[j],s2[k]});
                    break;
                }
                k++;
                j++;
            }
            if (k == s2.size() && s1.size() > s2.size()) { //abcd abc  return "" bcz lexilogically not possible
                return "";
            }
        }
        
        for(auto i:edges){
            if(!adj[i[0]].count(i[1])){
                adj[i[0]].insert(i[1]);
                indegree[i[1]]++;
            }
        }
        
        queue<char> q;
        for(auto i:indegree){
            if(i.second==0){
                q.push(i.first);
            }
        }
        
        string s="";
        while(!q.empty()){
            char c=q.front();
            q.pop();
            s+=c;
            for(char i:adj[c]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        if (s.size() != indegree.size())//check for cycles
            return "";
        return s;
    }
};