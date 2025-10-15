#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rs=0;
        int cs=0;
        int re=matrix.size()-1;
        int ce=matrix[0].size()-1;
        while(rs<=re&&cs<=ce){
            for(int i=cs;i<=ce;i++){
                ans.push_back(matrix[rs][i]);
            }
            rs++;
            for(int i=rs;i<=re;i++){
                ans.push_back(matrix[i][ce]);
            }
            ce--;
            if(rs<=re){
                for(int i=ce;i>=cs;i--){
                    ans.push_back(matrix[re][i]);
                }
                re--;
            }
            if(cs<=ce){
                for(int i=re;i>=rs;i--){
                    ans.push_back(matrix[i][cs]);
                }
                cs++;
            }
        }
        return ans;
    }
};