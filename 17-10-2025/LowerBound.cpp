#include<bits/stdc++.h>
using namespace std;
int LowerBound(vector<int> arr,int val){
    for(int i=0;i<arr.size();i++){
        if(arr[i]>=val)return i;
    }
    return arr.size();
}
int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    cout<<LowerBound(arr,7);
}