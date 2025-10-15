#include<bits/stdc++.h>
using namespace std;
// User function template for C++
class Solution {
  public:
    // Function to return sum of elements
    int arraySum(vector<int>& arr) {
        int ans=0;
        for(int i:arr)ans+=i;
        return ans;
    }
};