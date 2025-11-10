#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            string a=t.first;
            int b=t.second;
            if(a==endWord)return b;
            for(int i=0;i<beginWord.size();i++){
                string temp=a;
                for(int j=0;j<26;j++){
                    temp[i]='a'+j;
                    auto it=s.find(temp);
                    if(it!=s.end()){
                        q.push({temp,b+1});
                        s.erase(it);
                    }
                }
            }
        }
        return 0;
    }
};