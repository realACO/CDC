#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxLength(vector<int>& arr) {
        //convert the array into prefix sum
        int temp=0;
        for(int i=0;i<arr.size();i++){
            temp+=arr[i];
            arr[i]=temp;
        }

        //m1 stores the last occurence index of a element in prefix array
        unordered_map<int,int> m1;
        for(int i=0;i<arr.size();i++){
            m1[arr[i]]=i;
        }

        //m2 strores the first occurence of a element in prefix sum array
        unordered_map<int,int> m2;
        for(int i=arr.size()-1;i>=0;i--){
            m2[arr[i]]=i;
        }
        
        //now the basic concept i am using is that if any element repeats itself in prefix array then the sum of elements between those elements are 0, 
        //since i have leftmost and rightmost index og a element i can easilt compute that by doing m1[arr[i]]-m2[arr[i]]
        //edge case if any element is 0 then the sumof element from start to that element is 0
        //maintain maxi to store the max occuring chartecter
        //0(n) good approach but one map can be avoided but wouldnt make any significant difference
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)maxi=max(maxi,i+1);
            maxi=max(maxi,m1[arr[i]]-m2[arr[i]]);
        }
        return maxi;
    }
};