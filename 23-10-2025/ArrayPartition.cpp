#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());//sort the aray
        int ans=0;
        ///since we want the sum of minimmum of every two conswcutive elements,
        //we pair every 2 consecutive elements starting from begenning, 
        //we dont need to wxplicitly fin the min out of those pairs 
        //we can just diirectly sum the elements at even inde like 0 2 4 6 
        //return the sum
        for(int i=0;i<nums.size()-1;i+=2){
            ans+=nums[i];
        }
        return ans;
    }
};


//solution 2 count sort

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> c(20001);//since racge of elemens in nunms id between -10000 to 10000 we make a vector of sixe 20001
        //-10000 is represented by index 0 and 0 is represented by 10000
        for(int i:nums){
            c[i+10000]++;
        }
        int ans=0;
        bool t=true;//we want every alternate elements to be inside the ans so we set t as true as we add element we set t to !t making sure only alternate lements gets into ans
        for(int i=0;i<20001;i++){
            while(c[i]>0){
                if(t){
                    ans+=i-10000;
                }
                c[i]--;
                t=!t;
            }
        }
        return ans;
    }
};