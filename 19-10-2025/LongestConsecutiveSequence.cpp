#include<bits/stdc++.h>
using namespace std;

//o(nlogn) not optimised
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1)return nums.size();
        set<int> s;
        for(int i:nums)s.insert(i);
        nums.clear();
        for(int i:s)nums.push_back(i);
        //change all element of nums to unique and ordered values like set

        int maxi=INT_MIN;
        int c=1;
        int last=nums[0];
        for(int i=1;i<nums.size();i++){
            //increment count sequence is still there
            if(last+1==nums[i]){
                c++;
                //maintain maxi
                maxi=max(maxi,c);
                last=nums[i];
            }
            //reset count as soon as the sequence breaks
            else{
                c=1;
                last=nums[i];
            }
        }
        maxi=max(maxi,c);
        return maxi;
    }
};

//o(n) optimised
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1)return nums.size();
        unordered_set<int> s;
        for(int i:nums)s.insert(i);
        int maxi=0;
        
        for(int i:s){
            //we will start fron the element that has no previous element in it that is set doesnt have i-1 in it
            if(!s.count(i-1)){
                //initialize count and last if the first of psble longest sequence found
                int c=1;
                int last=i;
                //increment count till you find last +1 in the set
                while(s.count(last+1)){
                    c++;
                    //maintain maxi
                    maxi=max(maxi,c);
                    last=last+1;
                }
                maxi=max(maxi,c);
            }
        }
        return maxi;
    }
};