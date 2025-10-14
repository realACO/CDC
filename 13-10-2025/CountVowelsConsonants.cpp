#include<bits/stdc++.h>
using namespace std;
void CountVnC(string s){
    for(int i=0;i<s.size();i++){
        s[i]=tolower(s[i]);
    }
    int v=0;
    int c=0;
    int w=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')v++;
        if(s[i]==' ')w++;
        else{
            c++;
        }
    }
    cout<<v<<" "<<c<<" "<<w;
}
int main(){
    string s="Hello I am ASHISH";
    CountVnC(s);
    return 0;
}