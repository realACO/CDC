#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cmax=nums[0];//stores the larges product likely positive number
        int cmin=nums[0];//stores the smallest product likely negative number
        int mp=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)swap(cmax,cmin);//we swap cmax, and cmin as soon as the sign changes because for a -ve no we want to mutiply it with a negative no to maximise it and for a positive number we want to multiply it witha positive number to maximise it
            cmax=max(nums[i],nums[i]*cmax);
            cmin=min(nums[i],nums[i]*cmin);

            //store the max product in  mp
            mp=max(mp,cmax);
        }
        return mp;
    }
};