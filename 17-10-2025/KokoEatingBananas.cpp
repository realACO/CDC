#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // minimize k in such a way that all bananas can be eaten in h hours


    //healper function checks if it is possible for k to be the ans and if so thn return true or false
    bool helper(vector<int>& piles, int h,int k){
        //long long to svoid over flow
        long long a=0;
        for(int i:piles){
            //adds i/k's ceil value to if bcz if we have 5 bananas ina apile and koko can only eat 4 per hour then koko would need 2 hours to complete thus pile
            a=a+ceil((double)i/k);
        }
        return a<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //we will use bianary search here our search space is between 1 and the sum of al the elements of the vector
        int maxi=INT_MIN;
        for(int i:piles){
            maxi=max(maxi,i);
        }
        int s=1;
        int e=maxi;
        int ans;
        while(s<=e){
            int m=s+(e-s)/2;
            if(helper(piles,h,m)){
                ans=m;
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return ans;
    }
};