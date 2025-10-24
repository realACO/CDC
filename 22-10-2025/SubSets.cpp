#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i,vector<vector<int>> &ans,vector<int> &n,vector<int> &nums){
        //base case when index larger than equal to nums.size() push the vector n to ans and return 
        if(i>=nums.size()){
            ans.push_back(n);
            return;
        }
        //at each step we will eigther include the value at ith index or not
        //then recursivelt call the function for other remaining parts
        n.push_back(nums[i]);
        dfs(i+1,ans,n,nums);
        n.pop_back();
        dfs(i+1,ans,n,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> n;
        dfs(0,ans,n,nums);
        return ans;
    }
};

//                        start               
//             [1]                    []
//     [1,2]          [1]        [2]      []
// [1,2,3] [1,2]  [1,3] [1]  [2,3] [2]  [3] []