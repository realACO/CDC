#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        int c=0;
        int temp=0;
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            temp+=arr[i];
            arr[i]=temp;
            if(temp==0)c++;
            m[arr[i]]++;
        }

        // no of subarrays with sum 0 will be firsly the sum of occurence of 0 in sum array+ no of occurence of each element n*(n-1)/2 
        //int example array 0 0 5 5 0 0
        // the prefix sum is 0 0 5 10 10 10 
        //ans=0;
        //no of occurencce of 0 in sum array ans+=2   //2
        //no of occ of 0=2, 2(2-1)/2=1 ans+=1    //3
        //no of occurence of 5=1  1(1-1)/2=0 ans+=0    //3
        //no of occurences of 10=3  3(3-1)/2=3  ans+=3   //6
        //ans=6 return 
        for(auto &i:m){
            if(i.second>0){
                c+=i.second*(i.second-1)/2;
            }
        }
        return c;
    }
};