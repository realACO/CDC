#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//floyd cycle detecion
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;

        //fast and slow pointers to detect the loop
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast)break;
        }

        //moving another slow pointer and the already used fast pointers bu 1 till they meet the intersection point is the repeated element
        int slow2=0;
        while(slow2!=fast){
            fast=nums[fast];
            slow2=nums[slow2];
        }
        return fast;
    }
};