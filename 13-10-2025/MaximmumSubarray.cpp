#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        int maxi=arr[0];
        //let the first element is the maximmum subarray sum til now
        for (int i = 0; i < n; i++) {
            sum=sum+arr[i];
            //since our array consist of both psitive and negative numbers we cant just take the sum of all elements and return it
            //we need to set the sum to 0 each time the each time the prefix sums goes e\negative 
            //and store the maximmum in maxi
            maxi=max(maxi,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};