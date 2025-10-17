#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0;
        int e=height.size()-1;
        int mw=0;
        while(s<e){
            int w=e-s;
            int h=min(height[s],height[e]);
            int mw1=w*h;
            mw=max(mw,mw1);
            if(height[s]<=height[e]){
                s++;
            }else{
                e--;
            } 
        }
        return mw;
    }
};