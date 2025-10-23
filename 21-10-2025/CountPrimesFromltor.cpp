#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> p(int n){
        vector<int> ans(n+1,1);
        ans[0]=ans[1]=0;
        for(int i=2;i*i<=n;i++){
            if(ans[i]){
                for(int j=i*i;j<=n;j+=i){
                    ans[j]=0;
                }
            }
        }
        return ans;
    }
    int countPrimes(int L, int R) {
        // code here
        vector<int> ans;
        ans=p(R);
        int temp=0;
        for(int i=0;i<ans.size();i++){
            temp+=ans[i];
            ans[i]=temp;
        }
        if(L==0)return ans[R];
        return ans[R]-ans[L-1];
    }
};