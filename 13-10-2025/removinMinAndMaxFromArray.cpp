#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi=INT_MIN;
        int maxind;
        int mini=INT_MAX;
        int minind;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                maxind=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                minind=i;
            }
        }

        //max position to delete from start of vector
        int a=max(maxind,minind)+1;

        //max position to delete from end of vector
        int b=nums.size()-min(maxind,minind);

        //one element is on left side and one element is on right side
        int c=min(maxind,minind)+1+nums.size()-max(maxind,minind);

        //min of all posiible ans wers is answer
        int ans=min({a,b,c});

        return ans;
    }
};

//https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/