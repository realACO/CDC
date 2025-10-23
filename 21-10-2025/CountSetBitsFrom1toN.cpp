#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countSetBits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int x=i;//store i in x because cant make changes directly to i
            while(x){
                x=x&(x-1);//classic trick in bit manipulation, x&(x-1) renoves the right most set bit from the number
                //ex 6 (110) & 6-1=5(101)=100->left most setbit of 6 is removed 
                ans++;//increament ans whenever a set bit is removed
            }
        }
        return ans;
    }
};
//brute force does not work


class Solution {
  public:
    int largestPow(int n) {
        int c = 0;
        while ((1 << c) <= n) c++;
        return c - 1;
    }
    int countSetBits(int n) {
        if(n==0)return 0;
        int x= largestPow(n);
        int y=(1<<(x-1))*x;
        int z=n-(1<<x);
        return y+(z+1)+countSetBits(z);
    }
};
//ex for n=9
// 0000-0
// 0001-1
// 0010-2
// 0011-3
// 0100-4
// 0101-5
// 0110-6
// 0111-7
// 1000-8
// 1001-9

//take the larges pow less than n which is 3 say x
//we will make a formulae of calculate no of set bits till 2^3 that is till 0111
//no of set bits till 0111 = 12 which is 3*2^(3-1) genralised formula x*pow(2,x-1);
//now deal with other numbers left that is 1000 ans 1001
//no of bits from first bit of both will be equal to 9-pow(2,3)+1=2 geb=nralised formulae is n-pow(2,x)+1
//rest bits of both number 000 001
//for these number we will recursively call the function for n-pow(2,x)

//final single line 
// fn(n){
//     x=largestpow(n);
//     return x*pow(2,x-1) +n-pow(2,x)+1 +fn(n-pow(2,x))
// }

