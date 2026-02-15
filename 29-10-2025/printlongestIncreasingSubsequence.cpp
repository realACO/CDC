#include<bits/stdc++.h>
using namespace std;
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n)
{
	int res=0;
	int s=0;
    vector<int> dp(n,1);
	vector<int> hash(n);
	for(int i=0;i<n;i++)hash[i]=i;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
				if(dp[i]<1+dp[j]){
					dp[i]=1+dp[j];
					hash[i]=j;
				}
			}
        }
    }
	// for(auto i:hash)cout<<i<<endl;
    for(int i=0;i<n;i++){
		if(dp[i]>res){
			res=dp[i];
			s=i;
		}
	}

	vector<int> ans;
	int i=s;
	while(res!=0){
		ans.push_back(arr[i]);
		i=hash[i];
		res--;
	}
	reverse(ans.begin(),ans.end());
    return ans;
}


//lexicographically smallest
class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j])dp[i]=max(dp[i],1+dp[j]);
            }
        }
        int l=0;
        int s=0;
        for(int i=0;i<n;i++){
	    	if(dp[i]>l){
	    		l=dp[i];
	    		s=i;
	    	}
	    }
        vector<int> ans;
	    int i=s;
	    int t=l;
	    while(t!=0){
	    	ans.push_back(arr[i]);
	    	for(int j=0;j<i;j++){
	    		if(dp[j]==t-1 && arr[j]<arr[i]){
	    		    i=j;
	    		    break;
	    		}
	    	}
	    	t--;
	    }
	    reverse(ans.begin(),ans.end());
        return ans;
    }
};


