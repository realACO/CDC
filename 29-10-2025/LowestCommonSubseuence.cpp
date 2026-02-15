#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int helper(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
        if(ind1==-1 || ind2==-1){
            return 0;
        }
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2]){
            return dp[ind1][ind2]=1+helper(ind1-1, ind2-1, s1,s2,dp);
        }
        int a=helper(ind1-1,ind2,s1,s2,dp);
        int b=helper(ind1,ind2-1,s1,s2,dp);
        return dp[ind1][ind2]=max(a,b);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return helper(text1.size()-1,text2.size()-1,text1,text2,dp);
    }
};



// tabulation
class Solution {
  public:
    int lcs(string &s1, string &s2) {
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i=0;i<s1.size()+1;i++)dp[i][0]=0;
        for(int i=0;i<s2.size()+1;i++)dp[0][i]=0;
        
        for(int i=1;i<s1.size()+1;i++){
            for(int j=1;j<s2.size()+1;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
        
    }
};
