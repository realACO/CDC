#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int fn(int ind, vector<int> &nums, vector<int> &dp){
    //     if(ind>=nums.size()){
    //         return 0;
    //     }
    //     if(dp[ind]!=-1){
    //         return dp[ind];
    //     }
    //     int p=nums[ind]+fn(ind+2,nums,dp);
    //     int np=fn(ind+1,nums,dp);
    //     return dp[ind]=max(p,np);
    // }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> m;
        int t=INT_MIN;
        for(auto i:nums){
            t=max(i,t);
            m[i]++;
        }

        int prev=0;
        int prev2=0;
        for(int i=1;i<t+1;i++){
            int p=i*m[i];
            if(i>1)p+=prev2;
            int np=prev;
            int c=max(p,np);
            prev2=prev;
            prev=c;
        }
        // return fn(0,vals,dp);
        return prev;
    }
};