#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    unordered_map<char,int> m;
    string res="";
    for(char i:s){
        if(m[i]==0)res+=i;
        m[i]++;
    }
    cout<<res;
    return 0;
}