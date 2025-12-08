#include <bits/stdc++.h> 
using namespace std;
//recurstion + memoization
int helper(int i,int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
	int n=triangle.size();
	if(j>i)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	if(i==n-1)return triangle[n-1][j];
	int d=triangle[i][j]+helper(i+1,j,triangle,dp);
	int dd=triangle[i][j]+helper(i+1,j+1,triangle,dp);
	return dp[i][j]=min(d,dd);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n,vector<int>(n,-1));
	return helper(0,0,triangle,dp);
}

//tabulation top down approach
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp=triangle;
        int n=triangle.size();
        int t=0;
        for(int i=0;i<n;i++){
            t+=triangle[i][0];
            dp[i][0]=t;
        }

        t=0;
        for(int i=0;i<n;i++){
            t+=triangle[i][i];
            dp[i][i]=t;
        }

        for(int i=2;i<n;i++){
            for(int j=1;j<i;j++){
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};


//bottom up dp
class Solution {
  public:
    int minPathSum(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d=triangle[i][j]+dp[i+1][j];
                int dd=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(d,dd);
            }
        }
        return dp[0][0];
    }
};

//bottom up space optimization
class Solution {
  public:
    int minPathSum(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++){
            dp[i]=triangle[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--){
            vector<int> temp(dp.size()-1);
            for(int j=i;j>=0;j--){
                int d=triangle[i][j]+dp[j];
                int dd=triangle[i][j]+dp[j+1];
                temp[j]=min(d,dd);
            }
            dp=temp;
        }
        return dp[0];
    }
};
