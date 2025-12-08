#include <bits/stdc++.h> 
using namespace std;
class Solution {
private:
    int helper(int ind, int target, vector<int> &nums){
        if(ind==0){
            if(nums[0]==0 && target==0)return 2;
            if(target==0)return 1;
            if(nums[0]==target)return 1;
            return 0;
        }
        int p=helper(ind-1,target,nums);
        if(nums[ind]<=target)p+=helper(ind-1,target-nums[ind],nums);
        return p;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int t=0;
        for(int i:nums)t+=i;
        if((t-target)<0 || (t-target)%2==1)return 0;
        vector<vector<int>> dp(nums.size(),vector<int>((t-target)/2+1,0));
        for(int i=0;i<=(t-target)/2;i++){
            if(nums[0]==0 && i==0)dp[0][i]=2;
            else if(i==0)dp[0][i]=1;
            else if(nums[0]==i)dp[0][i]=1;
        }
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<=(t-target)/2;j++){
                int p=dp[i-1][j];
                if(nums[i]<=j)p+=dp[i-1][j-nums[i]];
                dp[i][j]=p;
            }
        }
        return dp[nums.size()-1][(t-target)/2];
    }
};


