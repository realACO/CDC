#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i:arr)q.push(i);
        int ans=0;
        while(q.size()!=1){
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            int x=a+b;
            q.push(x);
            ans+=x;
        }
        return ans;
    }
};