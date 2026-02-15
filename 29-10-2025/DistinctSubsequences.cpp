#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int helper(int ind1, int ind2, string &s1, string &s2,vector<vector<int>> &dp){
        if(ind2<0){
            return 1;
        }
        if(ind1<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2])return dp[ind1][ind2]=helper(ind1-1,ind2,s1,s2,dp)+helper(ind1-1,ind2-1,s1,s2,dp);
        return dp[ind1][ind2]=helper(ind1-1,ind2,s1,s2,dp);
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return helper(s.size()-1,t.size()-1,s,t,dp);
    }
};


//tabulation
class Solution {
  public:
    int subseqCount(string &str, string &sub) {
        int mod=1e9+7;
	    vector<vector<int>> dp(str.size()+1,vector<int>(sub.size()+1,0));
	    for(int i=0;i<=str.size();i++)dp[i][0]=1;
	    for(int i=1;i<=str.size();i++){
	    	for(int j=1;j<=sub.size();j++){
	    		if(str[i-1]==sub[j-1])dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
	    		else{
	    			dp[i][j]=dp[i-1][j]%mod;
	    		}
	    	}
	    }
	    return dp[str.size()][sub.size()]%mod;
    }
};



//space optimization
class Solution {
  public:
    int subseqCount(string &str, string &sub) {
	    vector<int> dp(sub.size()+1,0);
	    dp[0]=1;
	    for(int i=1;i<=str.size();i++){
	        vector<int> temp(sub.size()+1,0);
	        temp[0]=1;
	    	for(int j=1;j<=sub.size();j++){
	    		if(str[i-1]==sub[j-1])temp[j]=(dp[j-1]+dp[j]);
	    		else{
	    			temp[j]=dp[j];
	    		}
	    	}
	    	dp=temp;
	    }
	    return dp[sub.size()];
    }
};


// more space optimised
class Solution {
  public:
    int subseqCount(string &str, string &sub) {
	    vector<int> dp(sub.size()+1,0);
	    dp[0]=1;
	    for(int i=1;i<=str.size();i++){
	    	int c1=dp[0];
	    	for(int j=1;j<=sub.size();j++){
	    	    int c=dp[j];
	    		if(str[i-1]==sub[j-1])c=(c1+dp[j]);
	    		c1=dp[j];
	    		dp[j]=c;
	    	}
	    }
	    return dp[sub.size()];
    }
};



class Solution {
  public:
    int subseqCount(string &str, string &sub) {
	    vector<int> dp(sub.size()+1,0);
	    dp[0]=1;
	    for(int i=1;i<=str.size();i++){
	    	for(int j=sub.size();j>=1;j--){
	    		if(str[i-1]==sub[j-1])dp[j]=(dp[j-1]+dp[j]);
	    	}
	    }
	    return dp[sub.size()];
    }
};