#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        unordered_map<char,int> m;
        for(char c:s)m[c]++;
        unordered_map<char,int> m1;
        for(char c:t)m1[c]++;
        return m==m1;
    }
};