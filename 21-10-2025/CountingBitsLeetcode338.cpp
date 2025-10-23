#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSetBits(int n) {
        int c=0;
        while(n){
            n=n&(n-1);
            c++;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            ans.push_back(countSetBits(i));
        }
        return ans;
    }
};