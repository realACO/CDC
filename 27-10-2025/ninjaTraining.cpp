#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    int helper(int days, int last, vector<vector<int>> &nums, vector<vector<int>> &dp){
        if(days==0){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    maxi=max(maxi,nums[0][i]);
                }
            }
            return maxi;
        }
        if(dp[days][last]!=-1){
            return dp[days][last];
        }
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,nums[days][i]+helper(days-1,i,nums,dp));
            }
        }
        return dp[days][last]=maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int days=arr.size();
        int maxi=0;
        vector<vector<int>> dp(days,vector<int>(4,-1));
        for(int i=0;i<3;i++){
            maxi=max(maxi,helper(days-1,i,arr,dp));
        }
        return maxi;
    }
};


class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int days=arr.size();
        vector<vector<int>> dp(days,vector<int>(4,-1));
        dp[0][0]=max(arr[0][1],arr[0][2]);
        dp[0][1]=max(arr[0][0],arr[0][2]);
        dp[0][2]=max(arr[0][1],arr[0][0]);
        dp[0][3]=max({arr[0][1],arr[0][2],arr[0][0]});
        for(int i=1;i<days;i++){//days
            for(int j=0;j<3;j++){//last
                dp[i][j]=0;
                for(int k=0;k<3;k++){//other than last
                    if(j!=k){
                        dp[i][j]=max(dp[i][j],arr[i][k]+dp[i-1][k]);
                    }
                }
            }
        }
        return max({dp[days-1][0],dp[days-1][1],dp[days-1][2]});
    }
};


class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int days=arr.size();
        int a=max(arr[0][1],arr[0][2]);
        int b=max(arr[0][0],arr[0][2]);
        int c=max(arr[0][1],arr[0][0]);
        int d=max({arr[0][1],arr[0][2],arr[0][0]});
        vector<int> temp={a,b,c,d};
        for(int i=1;i<days;i++){
            vector<int> t(4,0);
            for(int j=0;j<3;j++){
                t[j]=0;
                for(int k=0;k<3;k++){
                    if(j!=k){
                        t[j]=max(t[j],arr[i][k]+temp[k]);
                    }
                }
            }
            temp=t;
        }
        return max({temp[1],temp[0],temp[2]});
    }
};