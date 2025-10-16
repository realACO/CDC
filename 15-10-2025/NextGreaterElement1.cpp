#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        //map to store next greater element of each element of nums2 corresponding to its value
        stack<int> s;
        //maintain monotonic increasing stack
        for(int i:nums2){
            while(!s.empty()&&s.top()<i){
                m[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        //reuse nums2 to store answer
        nums2.clear();
        for(int i:nums1){
            //push back the element whose next greater elemtn is found in map
            if(m[i])nums2.push_back(m[i]);
            //if not found that means its eigther last element of there is no next greater element
            else{
                nums2.push_back(-1);
            }
        }
        return nums2;
    }
};