#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int reverseExponentiation(int n) {
        int t=n;
        int rev=0;
        while(n!=0){
            int rem=n%10;
            rev+=rev*10+rem;
            n=n/10;
        }
        long ans=pow(t,rev);
        return ans;
    }
};