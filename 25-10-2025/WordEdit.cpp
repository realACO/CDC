#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int med(int i,int j,string s1,string s2,vector<vector<int>> &dp){
        if(i>=s1.size())return s2.size()-j;
        if(j>=s2.size())return s1.size()-i;
        //base cases if one index is more than the length of other string return that string-index
        if(s1[i]==s2[j]){
            return dp[i][j]=med(i+1,j+1,s1,s2,dp);//if already stored in the memory then return it
        }
        //if not stored then calculate it
        if(dp[i][j]!=-1)return dp[i][j];
        int x=med(i+1,j,s1,s2,dp)+1;//delete
        int y=med(i,j+1,s1,s2,dp)+1;//insert
        int z=med(i+1,j+1,s1,s2,dp)+1;//update
        //calculate all possible senarios and store it in the memory
        return dp[i][j]=min({x,y,z});
    }
    int minDistance(string word1, string word2) {
        //cache would be of size word1* size word 2
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return med(0,0,word1,word2,dp);
    }
};