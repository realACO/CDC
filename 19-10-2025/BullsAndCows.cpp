#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> sc(10,0);
        vector<int> gc(10,0);
        //only 10 possible numbers so we make it of size 10, these vectors will help calculate cows
        int b=0;
        int c=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])b++;//straight forward if index on both the string are same then bull ++
            //else will make cows
            else{
                //we store count of each numbers in these vectors
                sc[secret[i]-'0']++;
                gc[guess[i]-'0']++;
            }
        }
        for(int i=0;i<sc.size();i++){
            //final cow will be the sum of min of every index in both the vectore
            //because only the common num of occurences of a number will the cows be or guessed right but wrong place
            c+=min(sc[i],gc[i]);
        }
        return to_string(b)+"A"+to_string(c)+"B";
    }
};