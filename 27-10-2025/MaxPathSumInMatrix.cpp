#include <bits/stdc++.h> 
using namespace std;
class Solution {
  private:
    int helper(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
        int n=mat.size();
        int m=mat[0].size();
        if(j<0 || j>=m){
            return INT_MIN;
        }
        if(i==0){
            return dp[0][j]=mat[0][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int u=helper(i-1,j,mat,dp);
        int l=helper(i-1,j-1,mat,dp);
        int r=helper(i-1,j+1,mat,dp);
        return dp[i][j]=mat[i][j] + max({u,l,r});
    }
  public:
    int maximumPath(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            ans=max(ans,helper(n-1,i,mat,dp));
        }
        return ans;
    }
};

#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp=matrix;
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            int l=0;
            int c=dp[i+1][j];
            int r=0;
            if(j>0)l+=dp[i+1][j-1];
            else{
                l=INT_MIN;
            }
            if(j<m-1)r+=dp[i+1][j+1];
            else{
                r=INT_MIN;
            }
            dp[i][j]=matrix[i][j]+max({l,c,r});
        }
    }

    int ans=INT_MIN;
    for(int i=0;i<m;i++){
        ans=max(ans,dp[0][i]);
    }
    return ans;
}