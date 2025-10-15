#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rs=0;
        int r=matrix.size()-1;
        int c=matrix[0].size()-1;
        while(c>=0&&rs<=r){
            int s=matrix[rs][c];
            if(s==target)return true;
            else if(s>target)c--;
            else{
                rs++;
            }
        }
        return false;
    }
};