#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        for(int i=0;i<n;i++)hash[i]=i;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 || nums[j]%nums[i]==0){
                    if(dp[i]<1+dp[j]){
                        dp[i]=1+dp[j];
                        hash[i]=j;
                    }
                }
            }
        }
        int ind=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i];
                ind=i;
            }
        }
        vector<int> ans;
        int m=nums[ind];
        while(maxi!=0){
            if(m%nums[ind]==0 || nums[ind]%m==0)ans.push_back(nums[ind]);
            ind=hash[ind];
            maxi--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//lexicologically largest
class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        sort(arr.rbegin(),arr.rend());
        int n=arr.size();
        vector<int> dp(n,1);
        vector<int> hash(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]%arr[i]==0){
                    if(dp[i]<1+dp[j]){
                        dp[i]=1+dp[j];
                        hash[i]=j;
                    }
                }
            }
        }
        int maxi=0;
        int s=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i];
                s=i;
            }
        }
        // for(auto i:dp)cout<<i<<endl;
        vector<int> ans;
        while(s!=-1){
            ans.push_back(arr[s]);
            s=hash[s];
        }
        
        return ans;
    }
};