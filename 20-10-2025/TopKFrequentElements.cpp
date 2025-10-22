#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //store count of each element in a map
        unordered_map<int,int> a;
        for(int i:nums){
            a[i]++;
        }

        //make a heap that stores a pair{count,element}
        priority_queue<pair<int,int>> ans;
        for(auto &p:a){
            ans.push({p.second,p.first});
        }
        //after insertion heap will sort the pairs based on count

        //pop out the first k elemets from the heap to a vector and return it
        nums.clear();
        for(int i=0;i<k;i++){
            pair<int,int> temp=ans.top();
            nums.push_back(temp.second);
            ans.pop();
        }

        return nums;
    }
};