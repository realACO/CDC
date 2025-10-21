#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0||s.size()==1)return s.size();
        unordered_map<char,int> m;
        int maxi=0;
        string temp="";
        int i=0;
        while(i<s.size()){
            //since each comparision creates a key in map with garbage value 0 we index our string from 1 that is 1 represent 0th index ,2 represent 1st index...
            if(!m[s[i]]){
                temp+=s[i];
                m[s[i]]=i+1;
            }
            else{
                //when we find a value in map greater that 0 that means some charecter have repeated so we clear out the temp
                //and reset i to the previous seen index-1 of the charecter 
                //also maintain maxi
                if(temp.size()>maxi)maxi=temp.size();
                temp="";
                i=m[s[i]]-1;
                m.clear();//this take O(n) time complexity which messes up the code
            }
            i++;
        }
        if(temp.size()>maxi)maxi=temp.size();
        return maxi;
    }
};




//optimal approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0||s.size()==1)return s.size();
        int maxi=0;
        vector<int> m(256,-1);//make a vector to track which elements are seen, wee will store the index of string element carresponding to acsii index of vector ex m[a]=6, is same as m[67]=6
        int l=0;
        int r=0;
        int len=0;
        while(r<s.size()){
            //update l when string element is in the map vector and its value is greater than l
            if(m[s[r]]!=-1&&m[s[r]]>=l){
                //update l to next element of the last seen l, ex if strig  is abcadef suppose l is in 0 and r is in 3
                //we check if s[r] is in the map vectore which its is (m[a]=0) and its value is 0 which is greter than equal to l
                //so we update l to next element of m[a] that is 1
                l=m[s[r]]+1;
            }
            //since we only keep pointers to the ends of subarray with uniqie value thid formular correctly calculates the length o fthe substr
            len=r-l+1;
            //maxi stores max values of len
            maxi=max(len,maxi);

            //store the current seen eleemnt
            m[s[r]]=r;
            r++;
        }
        return maxi;
    }
};