#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0;
        int e=height.size()-1;
        int mw=0;
        //max water is equal to length multiplied by breath 
        //length will me difference between start and end pointers
        //breath will me the minimmum of the value at both indeces
        while(s<e){
            //legngth
            int w=e-s;
            //breath
            int h=min(height[s],height[e]);

            //calculate temp max water
            int mw1=w*h;

            //store maximmum in mw

            //replace the smaller height indeces
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