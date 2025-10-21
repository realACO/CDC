#include<bits/stdc++.h>
using namespace std;
//brute force approach
//start iterating from i=strat to end of the vector
//for each iteration again iterate fromj=i+1 to end
//if duplicates are encountered then store it in ans
//there are chances that in the answer vector there are more that one simirlar elements
//but these elements will be adjacent to each other so while printing just check the same and print
vector<int> RepeatingElement(vector<int> arr){
    //store the count of each elemnt of arr in map
    unordered_map<int,int> m;
    for(int i:arr){
        m[i]++;
    }

    //any elent that have count more than 1 is repeating and is pushed in side the answer vector
    vector<int> ans;
    for(auto &i:m){
        if(i.second>1){
            ans.push_back(i.first);
        }
    }

    //time coplexity o(n)
    return ans;
}
int main(){
    vector<int> a={1,1,2,3,4,4,5,1,2};
    a=RepeatingElement(a);
    for(int i:a){
        cout<<i<<" ";
    }
    return 0;
}