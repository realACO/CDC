#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int helper(int ind, int cntTrans, vector<int> &prices, vector<vector<int>> &dp){
        if(ind==prices.size() || cntTrans==4)return 0;
        if(dp[ind][cntTrans]!=-1)return dp[ind][cntTrans];
        int ans=0;
        if(cntTrans==0){
            int f=0;
            int p=helper(ind+1, 1, prices, dp)-prices[ind];//buy
            int np=helper(ind+1, 0, prices, dp);//skip
            f=max(p,np);
            ans=max(ans,f);
        }
        else if(cntTrans==1){
            int f=0;
            int p=prices[ind]+helper(ind+1,2,prices, dp);//sell
            int np=helper(ind+1, 1, prices, dp);//skip
            f=max(p,np);
            ans=max(ans,f);
        }
        else if(cntTrans==2){
            int f=0;
            int p=helper(ind+1, 3, prices, dp)-prices[ind];//buy
            int np=helper(ind+1, 2, prices, dp);//skip
            f=max(p,np);
            ans=max(ans,f);
        }else if(cntTrans==3){
            int f=0;
            int p=helper(ind+1, 4, prices, dp)+prices[ind];//sell
            int np=helper(ind+1, 3, prices, dp);//skip
            f=max(p,np);
            ans=max(ans,f);
        }
        return dp[ind][cntTrans]=ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, -1));
        return helper(0,0, prices, dp);
    }
};

//tabulation
int maxProfit(vector<int>& prices)
{
    vector<vector<int>> dp(prices.size()+1, vector<int>(4,0));
    for(int i=prices.size()-1;i>=0;i--){
        for(int j=0;j<4;j++){
            int ans=0;
            if(j==0){
                int f=0;
                int p=dp[i+1][1]-prices[i];//buy
                int np=dp[i+1][0];//skip
                f=max(p,np);
                ans=max(ans,f);
            }
            else if(j==1){
                int f=0;
                int p=prices[i]+dp[i+1][2];//sell
                int np=dp[i+1][1];//skip
                f=max(p,np);
                ans=max(ans,f);
            }
            else if(j==2){
                int f=0;
                int p=dp[i+1][3]-prices[i];//buy
                int np=dp[i+1][2];//skip
                f=max(p,np);
                ans=max(ans,f);
            }else if(j==3){
                int f=0;
                int p=dp[i+1][4]+prices[i];//sell
                int np=dp[i+1][3];//skip
                f=max(p,np);
                ans=max(ans,f);
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][0];
}



//0(1)
int maxProfit(vector<int>& prices) {
        int a=0;
        int b=0;
        int c=0;
        int d=0;
        
        for(int i=prices.size()-1;i>=0;i--){
            int a1=0;
            int b1=0;
            int c1=0;
            int d1=0;
            for(int j=0;j<4;j++){
                int ans=0;
                if(j==0){
                    int f=0;
                    int p=b-prices[i];//buy
                    int np=a;//skip
                    f=max(p,np);
                    a1=max(ans,f);
                }
                else if(j==1){
                    int f=0;
                    int p=prices[i]+c;//sell
                    int np=b;//skip
                    f=max(p,np);
                    b1=max(ans,f);
                }
                else if(j==2){
                    int f=0;
                    int p=d-prices[i];//buy
                    int np=c;//skip
                    f=max(p,np);
                    c1=max(ans,f);
                }else if(j==3){
                    int f=0;
                    int p=0+prices[i];//sell
                    int np=d;//skip
                    f=max(p,np);
                    d1=max(ans,f);
                }
            }
            a=a1;
            b=b1;
            c=c1;
            d=d1;
        }
        return a;
    }





//ultimate space optimization
int maxProfit(vector<int>& prices) {
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    for(int i=prices.size()-1;i>=0;i--){
        a=max(b-prices[i],a);
        b=max(prices[i]+c,b);
        c=max(d-prices[i],c);
        d=max(prices[i],d);
    }
    return a;
}