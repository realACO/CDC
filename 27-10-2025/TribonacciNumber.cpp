#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        if(n==0)return 0;
        if(n<2)return n;
        int prev3=0;
        int prev2=1;
        int prev1=1;
        for(int i=2;i<n;i++){
            int c=prev1+prev2+prev3;
            prev3=prev2;
            prev2=prev1;
            prev1=c;
        }
        return prev1;
    }
};