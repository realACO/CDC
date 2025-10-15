#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        int t=n;
        int ans=0;
        while(n!=0){
            int rem=n%10;
            if(rem!=0&&t%rem==0)ans++;
            n/=10;
        }
        return ans;
    }
};