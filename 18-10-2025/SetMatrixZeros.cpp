#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        //store the row index where 0 comes
        set<int> r;
        //strore the column index where 0 comes
        set<int> c;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(int i=0;i<m.size();i++){
            for(int j:c){
                m[i][j]=0;
            }
        }
        for(int i=0;i<m[0].size();i++){
            for(int j:r){
                m[j][i]=0;
            }
        }
    }
};