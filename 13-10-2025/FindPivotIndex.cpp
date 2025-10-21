#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        //find sum of all elements of nums vector
        int ls=0;
        //iterate through the nums vector
        //for each indec chec if the ls==rs
        //rs=total-ls-nums[i]
        for(int i=0;i<nums.size();i++){
            int rs=total-ls-nums[i];
            if(rs==ls)return i;
            ls+=nums[i];
            //keep incrementing the value of ls
            //at each iterstion
        }
        return -1;
    }
};