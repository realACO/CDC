#include<bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int> arr,int target){
    int n=arr.size();
    int s=0;
    int e=n-1;
    while(s<=e){
        int m=s+(e-s)/2;
        if(arr[m]==target)return m;
        else if(arr[m]>target)e=m-1;
        else{
            s=m+1;
        }
    }
    return -1;

}
int main(){
    vector<int> arr={1,4,5,7,9,10,12,25};
    cout<<BinarySearch(arr,25);
    return 0;
}