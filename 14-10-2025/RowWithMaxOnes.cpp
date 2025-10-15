#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int max1row;
        int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1)c++;
                if(c>maxi){
                    maxi=c;
                    max1row=i;
                }
            }
        }
        vector<int> ans;
        ans.push_back(max1row);
        ans.push_back(maxi);
        return ans;
    }
};