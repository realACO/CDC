#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int delop(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i>=s1.size())return s2.size()-j;//if i reaches the end of the strig 1 then we return the remaining length in+ the string 2
        if(j>=s2.size())return s1.size()-i;//if j reaches the end of the strig 2 then we return the remaining length in the string 1
        if(s1[i]==s2[j])return dp[i][j]=delop(i+1,j+1,s1,s2,dp);
        if(dp[i][j]!=-1)return dp[i][j];
        int x=delop(i+1,j,s1,s2,dp);
        int y=delop(i,j+1,s1,s2,dp);
        return dp[i][j]=min(x,y)+1;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return delop(0,0,word1,word2,dp);
    }
};