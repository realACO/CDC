#include<bits/stdc++.h>
using namespace std;
void InsertionSort(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    vector<int> a={1,5,3,6,3,9,2};
    InsertionSort(a);
    for(int i:a){
        cout<<i<<" ";
    }
    return 0;
}