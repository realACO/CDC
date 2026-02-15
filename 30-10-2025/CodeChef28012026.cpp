#include <bits/stdc++.h>
using namespace std;
int helper(int ind, int prev, vector<int> &arr){
    if(ind==arr.size())return 0;
    int p=0;
    if(prev==-1 || prev+1==arr[ind] || arr[ind]==1)p=1+helper(ind+1,arr[ind],arr);
    int np=helper(ind+1,prev,arr);
    return max(p,np);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        
        cout<<helper(0,-1,arr)<<endl;
    }
    return 0;
}
