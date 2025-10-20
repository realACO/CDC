#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//in question we are given an array with numbers from 0 to n with one number missing from it
//a^a=0;
//0^b=b
    int missingNumber(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n+1;i++){
            ans=ans^i;
        }
        for(int i:nums){
            ans=ans^i;
        }
        //so after xor ing all the  elements twice the value which is left us the missing number'
        return ans;
    }
};