#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int c=0;
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        if(n<=0)return 0;
        towerOfHanoi(n-1,from,aux,to);
        c++;
        towerOfHanoi(n-1,aux,to,from);
        return c;
    }
};