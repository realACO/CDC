#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int m=0;
        //using 3 pointer approach and swaping the nums[n] with nums[s] when 0 encunterd and swaping nums[n] and nums[s] when 0 encounteres
        //increment s decrement end, increment n
        while(m<=e){
            if(nums[m]==0){
                swap(nums[m],nums[s]);
                m++;
                s++;
            }
            else if(nums[m]==2){
                swap(nums[m],nums[e]);
                e--;
            }
            else m++;
        }
    }
};