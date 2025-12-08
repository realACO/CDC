#include <bits/stdc++.h> 
using namespace std;
class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            dp[i]=mat[i][m-1];
        }
        for(int j=m-2;j>=0;j--){
            vector<int> temp(n);
            for(int i=0;i<n;i++){
                int du=INT_MIN;
                int dd=INT_MIN;
                int l=dp[i];
                if(i>0)du=dp[i-1];
                if(i<n-1)dd=dp[i+1];
                temp[i]=mat[i][j]+max({du,dd,l});
            }
            dp=temp;
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};