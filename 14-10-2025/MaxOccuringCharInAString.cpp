#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int maxi=0;
    char ans;
    unordered_map<char,int> m;
    for(char c:s){
        //at each iteration increment the count of each char
        m[c]++;
        //then check if count of the current elemnt in map is larges that maxi and if so then update maxi and store char in ans
        if(m[c]>maxi){
            maxi=m[c];
            ans=c;
        }
    }
    cout<<ans;
}