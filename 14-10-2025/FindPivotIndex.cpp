#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
        }
        int ls=0;
        for(int i=0;i<nums.size();i++){
            int rs=ans-ls-nums[i];
            if(rs==ls)return i;
            ls+=nums[i];
        }
        return -1;
    }
};