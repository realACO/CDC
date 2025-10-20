#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        sort(s.begin(),s.end());
        unordered_map<char,int> m;
        int maxi=INT_MIN;
        char ans=s[0];
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            if(m[s[i]]>maxi){
                ans=s[i];
                maxi=m[s[i]];
            }
        }
        return ans;
    }
};