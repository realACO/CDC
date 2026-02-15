#include<bits/stdc++.h>
using namespace std;

// bad way
string helper(int ind1, int ind2, string &s1, string &s2,vector<vector<string>>&dp){
	if(ind1==0 || ind2==0)return "";
	if(dp[ind1][ind2]!="")return dp[ind1][ind2];
	if(s1[ind1-1]==s2[ind2-1])return dp[ind1][ind2]=helper(ind1-1, ind2-1, s1,s2,dp)+string(1,s1[ind1-1]);
	string a=helper(ind1-1, ind2,s1,s2,dp);
	string b=helper(ind1,ind2-1, s1,s2,dp);
	if(a.size()>=b.size())return dp[ind1][ind2]=a;
	return dp[ind1][ind2]=b;
}
string findLCS(int n, int m,string &s1, string &s2){
	vector<vector<string>> dp(s1.size()+1,vector<string>(s2.size()+1,""));
	for(int i=1;i<s1.size()+1;i++){
		for(int j=1;j<s2.size()+1;j++){
			if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+s1[i-1];
			else{
				string a=dp[i-1][j];
				string b=dp[i][j-1];
				if(a.size()>=b.size())dp[i][j]=a;
				else{
					dp[i][j]=b;
				}
			}
		}
	}
	return dp[s1.size()][s2.size()];
}

// backtracking way better one

