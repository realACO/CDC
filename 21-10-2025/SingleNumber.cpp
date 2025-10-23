#include<bits/stdc++.h>
using namespace std;
//every number repreating twice except one number return that number
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(int i:nums)x=x^i;
        return x;
    }
};