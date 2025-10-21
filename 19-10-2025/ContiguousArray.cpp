#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//we mainatain a a count in which we increment by 1 when we encounter 1 and decrement by 1 when we encounter 0
//we will map each count to its index
//we iterate through each element to nums change count based on its values, check if the count is alrready maped, if so then we have encountered first subarray with equal no of 0 and 1 
//we store the length of that found sy=ub array in maxi if it is greater than maxi
//initialize the map with m[0]=-1; this will ensure the smallest subarraty like 01 and 10 are detected
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        m[0]=-1;
        int maxi=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)c--;
            else{
                c++;
            }
            if(m.count(c)){
                maxi=max(maxi,i-m[c]);
            }else{
                m[c]=i;
            }
        }
        return maxi;
    }
};
// Input: nums = [0,1,1,1,1,1,0,0,0]
// Output: 6
// Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.