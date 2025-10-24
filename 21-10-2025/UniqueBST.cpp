#include<bits/stdc++.h>
using namespace std;

//basic recursion
class Solution {
public:
    int numTrees(int n) {
        if(n<=1)return 1;
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=numTrees(i-1)*numTrees(n-i);
        }
        return ans;
    }
};

//little bit dp not too complex using memorization
class Solution {
public:
    //helper function to pass the dp vector also
    //this is called top down dp
    //no idea what is it, but understood the code
    int solve(int n,vector<int> &dp){
        if(n<=1)return 1;
        if(dp[n]!=-1)return dp[n];//if ans for n is inside dp vector return it directly
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=solve(i-1,dp)*solve(n-i,dp);
        }
        dp[n]=ans;
        return ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);//store values found till now
        return solve(n,dp);
    }
};

//best solution- just return the nth catalan number (2n)!/(n+1)!(n)!
class Solution {
public:
    int numTrees(int n) {
        if(n==1||n==0)return 1;
        long long res=1;
        for(int i=0;i<n;i++){
            res=res*(2*n-i)/(i+1);
        }
        res/=(n+1);
        return  res;
    }
};

class Solution {
//its complex i didnt undertand
public:
    int numTrees(int n) {
        vector<int> numTrees(n+1,1);
        for(int i=2;i<n+1;i++){
            int total=0;
            for(int j=1;j<i+1;j++){
                int l=j-1;
                int r=i-j;
                total+=numTrees[l]*numTrees[r];
            }
            numTrees[i]=total;
        }
        return numTrees[n];
    }
};