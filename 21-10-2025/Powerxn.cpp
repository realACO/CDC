#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, long long n) {
        if(n<0){//convert negative powers
            x=1/x;
            n=-n;
        }

        //
        double r=1;
        while(n>0){
            if(n%2==1){
                r=r*x;//when odd we will multiply the accumulated x to r
                //the loop of positive numbers will end up here as 2/2=1
                //final n==2 so r=1*17*17*17*17
            }
            //supose if n=17 x=4 it will go to if condn and update r to r*17 which is 1*17 =17
            //then we will square the base and half the power
            x=x*x;//x=17*17 x=17*17*17*17
            n=n/2;//n=4/2=2 n=2/2=1
        }
        return r;
    }
};
//this is known as fast exponentiation where we square the base and half the power making calculation of power more efficient