#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> m;
        for(char c:p)m[c]++;
        int c=p.size();
        int l=0;
        int r=0;
        vector<int> ans;
        while(r<s.size()){
            if(m[s[r]]>0)c--;
            m[s[r]]--;
            r++;
            if(c==0)ans.push_back(l);

            //it will increament the val of m[s[l]] if it was in the map
            //and increment the l index
            if(r-l==p.size()){
                if(m[s[l]]>=0)c++;//increment the c cooz we will need another match from the map to make it 0
                //ex s=abca p=abc
                //till r=2 is one anagram we store l in ans, now we increase m[s[l]] bcz its no longer in the window a:1 b:0 c:0
                //next iteration
                // m[s[r]]>= true so we decrement the c and in loop c==0 we push the left index
                m[s[l]]++;
                l++;
            }
        }
        return ans;
    }
};