#include<bits/stdc++.h>
using namespace std;
bool isPallindrome(int ind, int i,string &s){
    int st=ind;
    int e=i;
    while(st<=e){
        if(s[st]!=s[e])return false;
        st++;
        e--;
    }
    return true;
}
int helper(int ind, string &s, vector<int> &dp){
    if(ind==s.size())return 0;
    if(dp[ind]!=-1)return dp[ind];
    int ans=INT_MAX;
    for(int i=ind;i<s.size();i++){
        if(isPallindrome(ind,i,s)){
            int t=1+helper(i+1,s,dp);
            ans=min(ans,t);
        }
    }
    return dp[ind]=ans;
}
int palindromePartitioning(string str)
{
    vector<int> dp(str.size(),-1);
    return helper(0,str,dp)-1;
}


//tabulation
int palPartition(string &s) {
    vector<int> dp(s.size()+1,0);
    for(int i=s.size()-1;i>=0;i--){
        int ans=INT_MAX;
        for(int j=i;j<s.size();j++){
            if(isPallindrome(i,j,s)){
                int t=1+dp[j+1];
                ans=min(ans,t);
            }
        }
        dp[i]=ans;
    }
    return dp[0]-1;
}
