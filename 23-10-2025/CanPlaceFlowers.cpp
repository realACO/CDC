#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int i=1;
        nums.insert(nums.begin(),0);
        nums.push_back(0);
        while(i<nums.size()-1){
            if(nums[i]==1){
                i+=2;
            }
            else if(nums[i-1]==0&&nums[i]==0&&nums[i+1]==0){
                n--;
                nums[i]=1;
                i+=2;
            }else{
                i++;
            }
        }
        return n<=0;
    }
};