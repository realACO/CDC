#include<bits/stdc++.h>
using namespace std;
//recursive solution
// class Solution {
//   public:
//     int fn(int ind, vector<int>&h){
//         int n=h.size();
//         if(ind==0) return 0;
//         if(ind==1)return abs(h[1]-h[0]);
//         return min((fn(ind-1,h)+abs(h[ind]-h[ind-1])), (fn(ind-2,h)+abs(h[ind]-h[ind-2])));
//     }
//     int minCost(vector<int>& h) {
//         int n=h.size()-1;
//         return fn(n,h);
//     }
// };

//tabulation
// class Solution {
//   public:
//     int minCost(vector<int>& h) {
//         int n=h.size();
//         vector<int> dp(n);
//         dp[0]=0;
//         if(n>=1)dp[1]=abs(h[1]-h[0]);
//         for(int i=2;i<n;i++){
//             dp[i]=min((dp[i-1]+abs(h[i]-h[i-1])),(dp[i-2]+abs(h[i]-h[i-2])));
//         }
//         return dp[n-1];
//     }
// };


// tabulation optimised
class Solution {
  public:
    int minCost(vector<int>& h) {
        int n=h.size();
        if(n==1)return 0;
        int prev2=0;
        int prev=abs(h[1]-h[0]);
        for(int i=2;i<n;i++){
            int curr=min((prev+abs(h[i]-h[i-1])),(prev2+abs(h[i]-h[i-2])));
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
