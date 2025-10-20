#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n=arr.size();
        stack<int> s;
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(!s.empty()&&arr[i]<=s.top()){
                s.pop();
            }
            if(s.empty()){
                s.push(arr[i]);
                ans.push_back(-1);
                continue;
            }
            if(arr[i]>s.top()){
                ans.push_back(s.top());
                s.push(arr[i]);
            }
        }
        return ans;
    }
};