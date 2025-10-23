#include<bits/stdc++.h>
using namespace std;
//every number repeating thrice except one return that number
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int c=0;
            for(int j:nums){
                if((j>>i)&1)c++;//checking set bit
            }
            if(c%3==1)ans=ans|(1<<i);//setting set bit
        }
        return ans;
    }
};
//count no of set bits of all elements from 0th to 32nd bit position if count%3==1 then set that particular bit of answer to 1
//O(32*n)


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=1;
        while(i<n){
            if(nums[i]!=nums[i-1])return nums[i-1];
            i+=3;
        }
        return nums[n-1];
    }
};
//O(nlogn)



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0;
        int twos=0;
        for(int i:nums){
            //i will go in ones if it is not in twos
            //i will go in twos if it is in ones
            ones=(ones^i)&~twos;
            twos=(twos^i)&~ones;
        }
        //at the ones will have the one and only sinle repeating number
        return ones;
    }
};
//O(n) use bitwise operations in this