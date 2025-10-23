#include<bits/stdc++.h>
using namespace std;
//count no fo coprimes to n from 1 to n
class Solution {
  public:
    int etf(int n) {
        int c=n;//store n in c
        for(int i=2;i*i<=n;i++){
            if(n%i==0){//factor of n found
                while(n%i==0){
                    n=n/i;//divide n by i til n ig gone, ex n=12 i=2->12/2=6->6/2=3 ->3/2!=0 loop ends n=3 final val of  nis 3
                    //next iteration i=3 factor of n=3 , n/i=3/3=1, loop ends n=1;
                }
            c=c-c/i; //12-12/2=6
            //6-6/3=4
            }
        }
        //n=1 leave this step
        if(n>1)c=c-c/n;
        return c;
    }
};