#include<bits/stdc++.h>
using namespace std;
//gfg less optimised
class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        vector<vector<string>> ans;
        vector<string> used;
        used.push_back(beginWord);
        int level=0;
        queue<vector<string>> q;
        q.push({beginWord});
        
        while(!q.empty()){
            auto t=q.front();
            auto last=t.back();
            q.pop();
            
            if(t.size()>level){
                level++;
                for(auto i:used){
                    s.erase(i);
                }
            }
            
            if(last==endWord){
                if(ans.size()==0)ans.push_back(t);
                else if(ans[0].size()==t.size())ans.push_back(t);
            }
            
            for(int i=0;i<last.size();i++){
                string temp=last;
                for(int j=0;j<26;j++){
                    temp[i]='a'+j;
                    if(s.find(temp)!=s.end()){
                        t.push_back(temp);
                        q.push(t);
                        used.push_back(temp);
                        t.pop_back();
                    }
                }
            }
        }
        
        return ans;
    }
};


//optimised
class Solution {
private:
    void dfs(string str, string &b, vector<string> &seq, unordered_set<string> &s, vector<vector<string>> &ans, unordered_map<string,int> &m){
        if(str==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        for(int i=0;i<str.size();i++){
            string temp=str;
            for(int j=0;j<26;j++){
                temp[i]='a'+j;
                if(m.find(temp)!=m.end() && m[temp]+1==m[str]){
                    seq.push_back(temp);
                    dfs(temp, b, seq,s,ans,m);
                    seq.pop_back();
                }
            }
        }

    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());

        vector<vector<string>> ans;

        unordered_map<string,int> m;
        queue<string> q;
        q.push(beginWord);
        m[beginWord]=1;
        s.erase(beginWord);
        while(!q.empty()){
            string t= q.front();
            q.pop();
            if(t==endWord)break;
            for(int i=0;i<t.size();i++){
                string temp=t;
                for(int j=0;j<26;j++){
                    temp[i]='a'+j;
                    if(s.find(temp)!=s.end()){
                        q.push(temp);
                        m[temp]=m[t]+1;
                        s.erase(temp);
                    }
                }
            }
        }

        if(m.find(endWord)!=m.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, beginWord, seq,s,ans,m);
        }
        return ans;
    }
};