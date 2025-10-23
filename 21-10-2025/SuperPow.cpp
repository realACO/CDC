#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int MOD=1337;
    //same pow function as before with some % MOD everywhere we multiply
    int p(int x, int n) {
        x%=MOD;
        int r=1;
        while(n>0){
            if(n%2==1){
                r=(r*x) % MOD;
            }
            x=(x*x) % MOD;
            n>>=1;
        }
        return r;
    }

    int superPow(int a, vector<int>& b) {
        int r=1;
        for(int i:b)r= p(a,i) * p(r,10) % MOD ;//formulae for this functuion
        //exmaple [1,2,4];
        //r=1
        //i in b
        //r= a^1 * r^10= a^1 * 1^10=a^1
        //r= a^2 * r^10= a^2 * (a^1)^10=a^12
        //r= a^4 * r^10 =a^4 * (a^12)^10=a^a^124
        return r;
    }
};