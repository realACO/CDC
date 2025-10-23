#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k==2||k==5)return -1;
        int rem=1%k;
        for(int i=1;i<=k;i++){
            if(rem==0)return i;
            rem=((rem*10)+1)%k;
        }
        return -1;
    }
};
//example k=17
//rem=1%k=1;
//loop from 1 to k bcz after k the rem will repeat itself
//return i whenever the rem becomes 0
//rem=((rem*10)+1)%k
//use the above formulae to jump from 1 to 11 to 111 and so on and also check rem at each iteration
//if no value is returned throught the lopp then return -