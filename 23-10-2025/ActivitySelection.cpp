#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int activitySelection(vector<int> &s, vector<int> &f) {
        vector<pair<int,int>> a;
        for(int i=0;i<s.size();i++){
            a.push_back({f[i],s[i]});
        }
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            f[i]=a[i].first;
            s[i]=a[i].second;
        }
        
        int ans=1;
        int i=1;
        int last=0;
        while(i<s.size()){
            if(f[last]<s[i]){
                 last=i;
                 ans++;
            }
            i++;
        }
        return ans;
    }
};