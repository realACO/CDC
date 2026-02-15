#include <bits/stdc++.h> 
using namespace std;
class Solution {
private:
    int helper(int ind, int target, vector<int> &nums){
        if(ind==0){
            if(nums[0]==0 && target==0)return 2;
            if(target+nums[ind]==0 || target-nums[ind]==0)return 1;
            return 0;
        }
        int p=helper(ind-1, target+nums[ind], nums);
        int np=helper(ind-1, target-nums[ind], nums);
        return p+np;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums.size()-1, target, nums);
    }
};