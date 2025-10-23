#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n+1;i++)ans=ans^i;
        for(int i:nums)ans=ans^i;
        return ans;
    }
};

//example nums= 0,1,3
//step 1 since exactly one number is missing w edo xor of 0 to nums.size()+1
//i.e ans=0^1^2^3
//now we xor all the elements of nums to ans , the elemnts of nums will cancel itself out from ans, making nums left with the missing number