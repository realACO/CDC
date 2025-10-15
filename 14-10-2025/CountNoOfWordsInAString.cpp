#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    //take entire line as a input and store it in a string
    getline(cin,s);
    int ans=0;
    for(int i=0;i<s.size();i++){
        //increments value when space is encountered
        if(s[i]==' ')ans++;
    }

    //final ans is no of white spaces+1
    cout<<ans+1;
}