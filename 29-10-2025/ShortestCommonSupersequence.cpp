#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestCommonSupersequence(string s, string s2) {
        vector<vector<int>> dp(s.size()+1,vector<int>(s2.size()+1,0));
        for(int i=1;i<s.size()+1;i++){
            for(int j=1;j<s2.size()+1;j++){
                if(s[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    int a=dp[i-1][j];
                    int b=dp[i][j-1];
                    dp[i][j]=max(a,b);
                }
            }
        }
        string pnt="";
        int strt=s.size();
        int end=s2.size();
        while(strt!=0 && end!=0){
            if(s[strt-1]==s2[end-1]){
                pnt+=s[strt-1];
                strt--;
                end--;
            }else{
                if(dp[strt-1][end]>dp[strt][end-1]){
                    pnt+=s[strt-1]; 
                    strt--;
                }else{
                    pnt+=s2[end-1]; 
                    end--;
                }
            }
        }
        while(strt){
            pnt+=s[strt-1];
            strt--;
        }
        while(end){
            pnt+=s2[end-1];
            end--;
        }
        reverse(pnt.begin(),pnt.end());
        return pnt;
    }
};