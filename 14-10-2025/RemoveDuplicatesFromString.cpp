#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    unordered_map<char,int> m;
    string res="";
    for(char i:s){
        //add the chars that have count of 0 in the map add them when they are encountered first
        if(m[i]==0)res+=i;
        //then increment its count in map so that it is not added to res again
        m[i]++;
    }
    cout<<res;
    return 0;
}