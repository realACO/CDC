#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        stack<string> s;
        for(string c:arr){
            if(c=="+"||c=="-"||c=="*"||c=="^"||c=="/"){
                int x=stoi(s.top());s.pop();
                int y=stoi(s.top());s.pop();
                if(c=="+"){
                    s.push(to_string(y+x));
                }
                if(c=="-"){
                    s.push(to_string(y-x));
                }
                if(c=="*"){
                    s.push(to_string(y*x));
                }
                if(c=="/"){
                    int result = y / x;
                    if ((y % x != 0) && ((y < 0) != (x < 0))) result--;
                    //for condition of division of numbers of opposite symmbol
                    //y%x chek if rem is there
                    //(y < 0) != (x < 0) this check if the sign is opposite
                    //-8 /3 gives output -2
                    //but we want -3
                    s.push(to_string(result));
                }
                if(c=="^"){
                    s.push(to_string((int)pow(y,x)));
                }
            }else{
                s.push(c);
            }
        }
        return stoi(s.top());
    }
};