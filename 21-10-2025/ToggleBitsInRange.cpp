#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int toggleBits(int n, int l, int r) {
        for(int i=l;i<=r;i++){
            n=n^(1<<(i-1));
        }
        return n;
    }
};