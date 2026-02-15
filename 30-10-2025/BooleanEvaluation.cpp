#include<bits/stdc++.h>
using namespace std;
long long mod=1000000007;
int helper(int i, int j, int isTrue, string &s, vector<vector<vector<int>>> &dp){
    if(i>j)return 0;
    if(i==j){
        if(isTrue)return s[i]=='T';
        else return s[i]=='F';
    }
    if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
    int ans=0;
    for(int k=i+1;k<j;k+=2){
        long long LT=helper(i,k-1,1,s,dp);
        long long RT=helper(k+1,j,1,s,dp);
        long long RF=helper(k+1,j,0,s,dp);
        long long LF=helper(i,k-1,0,s,dp);
        long long t=0;
        if(s[k]=='&'){
            if(isTrue)t+=LT * RT;
            else t+= LT * RF + LF * RT + LF * RF ;
        }else if(s[k]=='|'){
            if(isTrue)t+= LT * RT+ LT * RF + LF * RT;
            else t+= LF * RF ;
        }else if(s[k]=='^'){
            if(isTrue)t+= LT * RF + LF * RT;
            else t+= LT * RT+ LF * RF ;
        }
        t=t%mod;
        ans=(ans+t)%mod;
    }
    return dp[i][j][isTrue]=ans;

}
int evaluateExp(string & exp) {
    int n=exp.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    return helper(0,exp.size()-1,1,exp,dp);
}