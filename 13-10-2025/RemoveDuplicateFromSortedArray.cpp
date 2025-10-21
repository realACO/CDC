#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        while(i<nums.size()&&j<nums.size()){
            //iterate i once throughout the vector we incerement j at both cases that is when its equal to nums[i] and when it is not
            //when nums[i] is not equal to nus[j] we know that it is supposed to come just after the ith index
            if(nums[i]!=nums[j]){
                nums[i+1]=nums[j];
                i++;
            }
            j++;
        }
        //return the size of the the nums which is free from duplicates
        return i+1;
    }
};