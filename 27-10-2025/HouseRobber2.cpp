#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    int func(int n,vector<int> &nums){
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int p=nums[i];
            if(i>1)p+=prev2;
            int np=prev;
            int c=max(p,np);
            prev2=prev;
            prev=c;
        }
        return prev;
    }
  public:
    int maxValue(vector<int>& arr) {
        int n=arr.size();
        vector<int> temp1(arr.begin(),arr.end()-1);
        int x=func(n-1,temp1);

        vector<int> temp2(arr.begin()+1,arr.end());
        int y=func(n-1,temp2);
        
        return max(x,y);
    }
};
