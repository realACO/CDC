#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string c="";
        for(int i=0;i<s.size();i++){
            if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')){
                s[i]=tolower(s[i]);
                c+=s[i];
            }
            if(s[i]>='0'&&s[i]<='9'){
                c+=s[i];
            }        
        }
        cout<<c;
        bool ans=true;
        int st=0;
        int e=c.size()-1;
        while(st<=e){
            if(c[st++]!=c[e--]){
                ans=false;
                break;
            }
        }
        return ans;
    }
};