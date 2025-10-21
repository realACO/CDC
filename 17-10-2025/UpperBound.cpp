#include<bits/stdc++.h>
using namespace std;
int UpperBound(vector<int> arr,int val){
    for(int i=0;i<arr.size();i++){
        if(arr[i]>val)return i;
    }
    return arr.size();
}
int UpperBoundd(vector<int> arr,int val){
    int s=0;
    int e=arr.size()-1;
    int ans=-1;
    //using binary search to so the same what we did earlier
    while(s<=e){
        int m=s+(e-s)/2;
        if(arr[m]>=val){
            ans=m;
            e=m-1;
        }else{
            s=m+1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    cout<<UpperBoundd(arr,7);
}