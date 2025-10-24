#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//very similar to subsets problem but here after backtracking we dont need to call the function again
    void backTracking(int c,int n,int k,vector<vector<int>> &ans,vector<int> &b){
        if(b.size()==k){//base case
            ans.push_back(b);
            return;
        }
        //for c=1 we will go till 1 to 4 and generate combinations of siize k
        //for c-3 we will go from 3 to 4 and generate all combinations of  size k
        for(int i=c;i<=n;i++){
            //same pick not pick logic inside the loop using back tracking 
            b.push_back(i);
            backTracking(i+1,n,k,ans,b);
            b.pop_back();
        }
    }

    //in this que we need to generate combinations of length k fron numbers 1 to n
    //we dont want duplicates like 1,2 and 2,1 
    //so we generate all the possible combinations from 1 of size k 
    //then we generate all the posiible combinations of 2 of size k exclusing 1
    //till n ....
    //put all of then in vector and return
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> b;
        backTracking(1,n,k,ans,b);
        return ans;
    }
};