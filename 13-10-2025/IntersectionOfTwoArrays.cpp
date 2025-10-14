#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(int i:nums1)m[i]++;
        unordered_map<int,int> m1;
        for(int i:nums2)m1[i]++;
        vector<int> ans;
        for(auto i:m){
            if(m1[i.first]>0)ans.push_back(i.first);
        }
        return ans;
    }
};