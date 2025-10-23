#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=0;
        for(int i=1;i<nums.size();i++){
            if((nums[i]^nums[i-1])==0)a=a^nums[i];
        }
        return a;
    }
};