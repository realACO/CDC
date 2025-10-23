#include<bits/stdc++.h>
using namespace std;
//method 1
class Solution {
  public:
    bool checkKthBit(int n, int k) {
        int x=1<<k;
        return x&n;
    }
};

//method 2
class Solution {
  public:
    bool checkKthBit(int n, int k) {
        n=n>>k;
        return n&1==1;
    }
};