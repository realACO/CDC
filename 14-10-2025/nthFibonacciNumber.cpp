// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        int n1=0;
        int n2=1;
        if(n==0)return 0;
        if(n==1)return 1;
        n=n-1;
        while(n--){
            int t=n2;
            n2=n2+n1;
            n1=t;
        }
        return n2;
    }
};