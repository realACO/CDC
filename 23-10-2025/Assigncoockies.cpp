#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
        sort(g.begin(),g.end());//sort the arrays in nlogn complexity to avoid n*m complexity inside while loop which is now at n+m
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        // basic two pointer
        while(i<g.size()&&j<s.size()){
            if(g[i]<=s[j]){
                ans++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return ans;//could directly return i coz its the same
    }
};