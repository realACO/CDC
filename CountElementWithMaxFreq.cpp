#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxi=INT_MIN;
        for(int i:nums){
            m[i]++;
            if(m[i]>maxi){
                maxi=max(maxi,m[i]);
            }
        }
        int ans=0;
        for(auto &i:m){
            if(i.second==maxi){
                ans+=i.second;
            }
        }
        return ans;
    }
};

//https://leetcode.com/problems/count-elements-with-maximum-frequency/description/