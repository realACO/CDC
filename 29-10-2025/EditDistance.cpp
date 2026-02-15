#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int helper(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
        if(ind1<0)return ind2+1;
        if(ind2<0)return ind1+1;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        int a=1+helper(ind1-1,ind2,s1,s2,dp);
        int b=helper(ind1-1,ind2-1,s1,s2,dp);
        if(s1[ind1]!=s2[ind2])b+=1;
        int c=1+helper(ind1,ind2-1,s1,s2,dp);
        return dp[ind1][ind2]=min({a,b,c});
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return helper(word1.size()-1,word2.size()-1,word1,word2,dp);
    }
};



//tabulation
class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i=0;i<=s1.size();i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=s2.size();j++){
            dp[0][j]=j;
        }
        
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=1+min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};



//space optimization
#include<bits/stdc++.h>
int editDistance(string s1, string s2)
{
    vector<int> dp(s2.size()+1,0);
    for(int i=0;i<=s2.size();i++){
        dp[i]=i;
    }
    
    vector<int> temp(s2.size()+1,0);
    for(int i=1;i<=s1.size();i++){
        temp[0]=i;
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1])temp[j]=dp[j-1];
            else{
                temp[j]=1+min({dp[j-1],temp[j-1],dp[j]});
            }
        }
        dp=temp;
    }
    return dp[s2.size()];
}