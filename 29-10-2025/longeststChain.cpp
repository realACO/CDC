#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isPossible(string &s1, string &s2){
        if(s1.size()==s2.size())return false;

        int i=0;
        int j=0;
        int c=0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i]!=s2[j]){
                c++;
                j++;
            }
            else{
                i++;
                j++;
            } 
        }
        return c==1&&j==s2.size()||c==0&&j==s2.size()-1;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end() ,[](const string &a,const string &b){
            return a.size()<b.size();
        });
        int n=words.size();
        vector<int> dp(n,1);
        vector<int> hash(n,-1);

        int maxi=0;
        int s=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isPossible(words[j],words[i])){
                    if(dp[i]<1+dp[j]){
                        dp[i]=1+dp[j];
                        hash[i]=j;
                    }
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                s=i;
            }
        }
        vector<string> ans;
        while(maxi!=0){
            ans.push_back(words[s]);
            s=hash[s];
            maxi--;
        }
        // for(auto i:ans)cout<<i<<" ";
        // cout<<endl;
        // for(auto i:hash)cout<<i<<" ";

        return ans.size();
    }
};



//coding ninjas
bool helper(string &a, string &b){
    if(a.size()==b.size())return false;
    int i=0;
    int j=0;
    int c=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]!=b[j]){
            j++;
            c++;
        }else{
            i++;
            j++;
        }
    }
    return c==1&&j==b.size()||c==0&&j==b.size()-1;
}
int longestStrChain(vector<string> &arr){
    int n=arr.size();

    sort(arr.begin(), arr.end(), [](const string &a, const string &b){
        return a.size()<b.size();
    });

    vector<int> dp(n,1);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(helper(arr[j],arr[i])){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        ans=max(dp[i],ans);
    }
    return ans;
}