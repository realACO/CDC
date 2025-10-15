#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    map<char,int> m;
    for(char c:s)m[c]++;
    for(auto &i:m)cout<<i.first<<i.second<<" ";
    return 0;
}