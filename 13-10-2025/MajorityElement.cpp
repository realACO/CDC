#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> a;
        int maxi=0;
        for(int i:nums){
            a[i]++;
            maxi=max(a[i],maxi);
        }

        int ans;
        for(auto &i:a){
            if(i.second==maxi){
                ans=i.first;
                break;
            }
        }
        return ans;
        
    }
};