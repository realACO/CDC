#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size()==1)return 1;
        int n=arr.size();
        int i=0;
        int last=-1;//if stores the maximmum element encountered so far only considered if arr[i]<i
        //we dont need seperate array to compare values just use the indexes of the array
        //example 4 3 1 0 2
        //we first se that arr[0]>0 4>0 we store it in last
        //arr[1]>1 we store it in last if it is larger than last
        //arr[2]<2 now it can be a potential breaking point, but since the largest number encountered so far is 4 but the current index is 2 we move onn without any changes
        //arr[3]<3 same case as before
        //arr[4]<4 now we check if the last is less that equal to index, which is true so we increment the ans
        int ans=0;
        while(i<arr.size()){
            if(arr[i]>i){
                last=max(last,arr[i]);
            }
            else if(arr[i]<i){
                if(last<=i){
                    ans++;
                }
            }else{
                if(arr[i]>last)ans++;
            }
            i++;
        }
        
        return ans;
    }
};



//easier way
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        long a=0;
        long b=0;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            a+=temp[i];
            b+=arr[i];
            if(a==b)ans++;
        }
        return ans;
    }
};