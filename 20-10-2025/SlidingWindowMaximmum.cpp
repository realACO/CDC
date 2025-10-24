#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        //use queue as a monotonic increasing stack that stores the index
        //iterate through all indeces og =f nums if if front of the queue is less than i-k then the front element is out of window, pop it
        //now check if new nums[index] is greater than q.front and if so pop element at q.front
        //lastly push the ith elemnt fron the back to q, and store the front most element of the stat to ans vector after k-1 index
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(!q.empty()&&q.front()<=i-k)q.pop_front();
            while(!q.empty()&&nums[i]>=nums[q.back()])q.pop_back();
            q.push_back(i);
            if(i>=k-1)ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};