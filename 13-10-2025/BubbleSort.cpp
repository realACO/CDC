#include<bits/stdc++.h>
using namespace std;
void BubbleSort(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size();j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main(){
    vector<int> a={1,5,3,6,3,9,2};
    BubbleSort(a);
    for(int i:a){
        cout<<i<<" ";
    }
    return 0;
}