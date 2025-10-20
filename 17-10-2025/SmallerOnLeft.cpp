#include<bits/stdc++.h>
using namespace std;
vector<int> Smallestonleft(int arr[], int n) {
    // code here
    set<int> s;
    //set stores unique values in a sorted order
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(s.empty()){
            //start case when set is empty
            ans.push_back(-1);
        }
        else{
            //finds first element greater that equal to aee[i]
            auto it=s.lower_bound(arr[i]);

            //when no element is greater than q=equal to val
            if(it==s.begin()){
                ans.push_back(-1);

            //when element and element exist that is greater than equal to val
            //just push its previous element to ans
            }else{
                it--;
                ans.push_back(*it);
            }
        }
        s.insert(arr[i]);
    }
    return ans;
}