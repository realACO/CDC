#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,0));
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=s.size();j++){
                if(s[i-1]==s1[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return s.size()-dp[s.size()][s.size()];
    }
};