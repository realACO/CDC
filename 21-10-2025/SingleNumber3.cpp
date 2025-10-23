#include<bits/stdc++.h>
using namespace std;
//every number repeating twice except 2 numbers returen those 2 numbers
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a=0;
        int b=0;
        long t=0;
        for(int i:nums)t=t^i;//when we xor every number in the array then we will be left with the xor of two distinct numbers which we have to return 
        //now we need to differentiate those two numbers somehow
        //we know that after xor of two numbers if we get a set bit in the answer then the two numbers have different values in that position
        //for example a^b=x 101^111=010<-the second bit from the left is set that mean the second bit of a and b are different
        t=(t&(t-1))^t;//we will extract that particular set bit using this formulae
        //for t=010  t&(t-1)=010&001=000^t=000^010=010 we got the set bit only from the total xor
        for(int i:nums){
            //we will & all the numbers of i with t if they are return a positive value it s xor'd to first variable
            if(i&t)a=a^i;
            else{
                //rest will be xored to second variable
                b=b^i;
            }
            //duplicates will only go to same variable therefore while xoring them it will cancel out each other
        }
        //at last we are left with a ad b with are unique
        return {a,b};
    }
};