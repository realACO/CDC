#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int> &nums,int low,int mid,int high){
        int left=low;
        int right=mid+1;
        vector<int> sorted;
        while(left<=mid&&right<=high){
            nums[left]<nums[right]?sorted.push_back(nums[left++]):sorted.push_back(nums[right++]); 
        }

        while(left<=mid)sorted.push_back(nums[left++]);
        while(right<=high)sorted.push_back(nums[right++]);

        for(int i=0;i<sorted.size();i++){
            nums[low+i]=sorted[i];
        }
    }
    void mergeSort(vector<int> &nums,int low,int high){
        if(low>=high)return;
        int mid=(high+low)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};