#include<bits/stdc++.h>
using namespace std;
//first way make a heap yourelf by heapifying it and pop k elemenets from it then return the topmost element
class Solution {
public:
    void heapify(vector<int> &a,int n,int r){
        if(r>=n)return;
        int max=r;
        if(2*r+1<n&&a[max]<a[2*r+1])max=2*r+1;
        if(2*r+2<n&&a[max]<a[2*r+2])max=2*r+2;
        if(r!=max){
            swap(a[r],a[max]);
            heapify(a,n,max);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(nums,n,i);
        }
        int ans;
        //poping works by swaping the top element with the last element shrinking size of array then again heapifying it
        for(int i=0;i<k;i++){
            ans=nums[0];
            swap(nums[0],nums[n-1]);
            n--;
            heapify(nums,n,0);
        }
        return ans;
    }
};

//using priority queue of max heap stl O(nlogn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int i:nums)q.push(i);
        for(int i=0;i<k-1;i++)q.pop();
        return q.top();
    }
};


//more optimised using min heap O(logn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i:nums){
            q.push(i);
            if(q.size()>k)q.pop();
        }
        return q.top();
    }
};