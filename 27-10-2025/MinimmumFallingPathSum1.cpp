#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> dp=matrix[n-1];
        for(int i=n-2;i>=0;i--){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                int l=INT_MAX;
                int r=INT_MAX;
                int c=dp[j];
                if(j>0)l=dp[j-1];
                if(j<n-1)r=dp[j+1];
                temp[j]=matrix[i][j]+min({l,r,c});
            }
            dp=temp;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[i]);
        }
        return ans;
    }
};