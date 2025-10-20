// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isBadVersion(int n){
        return false;
    }
    int firstBadVersion(int n) {
        int s=0;
        int e=n;
        int ans;
        while(s<=e){
            int m=s+(e-s)/2;
            if(isBadVersion(m)){
                ans=m;
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return ans;
    }
};