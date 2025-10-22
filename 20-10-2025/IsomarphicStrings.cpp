#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//if both strings have unique value in them then the ans is obviously true
//the problem arises when there are duplicates in the string
//we map each others value ina amap and whenever we encounter them again we check if the value stored in the map is same value as before
//if not rturn true
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> s1;
        unordered_map<char,int> t1;
        for(int i=0;i<s.size();i++){
            if(t1.count(s[i])&&t1[s[i]]!=t[i])return false;
            if(s1.count(t[i])&&s1[t[i]]!=s[i])return false;
            t1[s[i]]=t[i];
            s1[t[i]]=s[i];
        }
        return true;
    }
};