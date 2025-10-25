#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//make another duplicate array sort it
//calculate prefix sum of given array and sorted array whereever they match there is a partition

//example 1 0 1 3 2
//sorted duplicate array 0 1 1 2 3

//prefix sum of both
//1 1 2 5 7
//0 1 2 4 7
//    .   .
//second and fourth index matches so ans is 2
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        long a=0;
        long b=0;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            a+=temp[i];
            b+=arr[i];
            if(a==b)ans++;
        }
        return ans;
    }
};