#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {//example n=10
        int c=0;
        vector<bool> prime(n+1,true);//vector from 0 to 10
        prime[0]=prime[1]=false;//set 0 and 1 th index to false
        for(int i=2;i*i<n;i++){//iterate from i=2 till i*i<n
            if(prime[i]){//if ith idex of prime vector is true then set all the multiples of i starting from i=i*i or i+i till i less than n
                for(int j=i*i;j<n;j=j+i){
                    prime[j]=false;
                }
            }   
        }
        for(int i=0;i<n;i++){
            if(prime[i])c++;
        }
        return c;
    }
};