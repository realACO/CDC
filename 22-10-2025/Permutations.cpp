#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

//example nums= 1 2 3
//permute({1 2 3})
//  k={2 3}
//  p=permute({2 3})
//      k={3};
//      p=permute({3})
//          k={}
//          p=permute({})
//          return {{}}
//      for each vector in the p insert nums[0] ie 3 in each position
//      res={{3}}
//      return {{3}}
//  for each vector in the p insert nums[0] ie 2 in each position
//  res= {{2,3},{3,2}}
//  return {{2,3},{3,2}}
//for each vector in the p insert nums[0] ie 1 in each position
//res={{1 2 3}{2 1 3}{2 3 1}{1 3 2}{3 1 2}{3 2 1}}->all permutations

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0){
            return {{}};
        }
        vector<int> k(nums.begin()+1,nums.end());
        vector<vector<int>> p=permute(k);
        for(auto &i:p){
            for(int j=0;j<i.size()+1;j++){
                vector<int> temp=i;
                temp.insert(temp.begin()+j,nums[0]);
                res.push_back(temp);
            }
        }
        return res;
    }
};