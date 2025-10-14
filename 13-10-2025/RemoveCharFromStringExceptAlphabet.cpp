#include<bits/stdc++.h>
using namespace std;
string Remove(string s){
    string ans="";
    for(int i=0;i<s.size();i++){
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')){
            ans+=s[i];
        }
    }
    return ans;
}
int main(){
    string s="Hello I #$am% ASHISH";
    cout<<Remove(s);
    return 0;
}