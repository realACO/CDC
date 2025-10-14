#include<bits/stdc++.h>
using namespace std;
void SelectioSort(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        int minind=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[minind])minind=j;
        }
        swap(arr[i],arr[minind]);
    }
}
int main(){
    vector<int> a={1,5,3,6,3,9,2};
    SelectioSort(a);
    for(int i:a){
        cout<<i<<" ";
    }
    return 0;
}