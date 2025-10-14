#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        while(i<nums.size()&&j<nums.size()){
            if(nums[i]!=nums[j]){
                nums[i+1]=nums[j];
                i++;
            }
            j++;
        }
        return i+1;
    }
};