#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int ans=0;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
            res.push_back(ans);
        }

        return res;
    }
};

//https://leetcode.com/problems/running-sum-of-1d-array/description/s