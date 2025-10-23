#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int setBits(int n){
        int c=0;
        while(n){
            n=n&(n-1);
            c++;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        // ans.push_back(0);
        for(int i=0;i<=n;i++){
            ans.push_back(setBits(i));
        }
        return ans;
    }
};
//O(nlogn)


