#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> q;
        for(int i=0;i<arr.size();i++){
            q.push(arr[i]);
            if(q.size()>k)q.pop();
        }
        return q.top();
    }
};