#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> lm(h.size()),rm(h.size());
        //left maax and right max vector to store the left max and right max element of a value at index

        //initialize lm[0]to h[0], no element is to the left of lm[0]
        lm[0]=h[0];

        //start from sirst index of h and go till last
        for(int j=1;j<h.size();j++){
            //at each index the value of lm j wil me max of h[j] ans lm[j-1]
            lm[j]=max(h[j],lm[j-1]);
        }

        //initialize last element of h to last element of rm, bcz no element to the right of last element of rm
        rm[h.size()-1]=h[h.size()-1];
        for(int j=h.size()-2;j>=0;j--){
            rm[j]=max(h[j],rm[j+1]);
        }

        //max water calculation
        //for each index i the water it contributes is min(lm[j],rm[j])-h[j]
        //store its sum in water 
        int water=0;
        for(int i=0;i<h.size();i++){
            
            //index is larger that both left max and right max// so it can store no water
            if(lm[i]<h[i]||rm[i]<h[i]){
                continue;
            }else{
                water=water+(min(lm[i],rm[i])-h[i]);
            }
        }
        return water;
    }
};