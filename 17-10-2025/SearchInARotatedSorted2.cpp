#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            //case 1 nums[m]==target
            //case 2 both ends have same element shrink size
            //case 3 right side is sorted
            //case 4 left side is sorted
            int m=s+(e-s)/2;
            if(nums[m]==target)return true;
            else if(nums[m]==nums[s]&&nums[m]==nums[e]){
                s++;
                e--;
            }
            else if(nums[s]<=nums[m]){
                if(nums[s]<=target &&nums[m]>target){
                    e=m-1;
                }else{
                    s=m+1;
                }
            }
            else{
                if(nums[m]<target&&nums[e]>=target){
                    s=m+1;
                }else{
                    e=m-1;
                }
            }
        }
        return false;
    }
};