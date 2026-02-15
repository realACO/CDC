#include<bits/stdc++.h>
using namespace std;
int helper(int ind1, int ind2, string s1, string s2, vector<vector<int>>&dp){
    if(ind1==s1.size())return s2.size()-ind2;
    if(ind2==s2.size())return s1.size()-ind1;
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    if(s1[ind1]==s2[ind2])return dp[ind1][ind2]=helper(ind1+1, ind2+1, s1,s2,dp);
    int a=1+helper(ind1+1, ind2, s1,s2,dp);
    int b=1+helper(ind1, ind2+1, s1,s2,dp);
    return dp[ind1][ind2]=min(a,b);
}  
int canYouMake(string &s1, string &s2){
    vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return s1.size()+s2.size()-2*dp[s1.size()][s2.size()];
}