#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //we will find the pivot eleemnt, the do binary search on 0 to pivot-1 element and pivot to end of the array

    //in a rotated sorted array pivot element is the smallest elemen
    //ex 4 5 1 2 3
    //here pivot element is 1
    int pivotelement(const vector<int>& a){
        int n=a.size();
        int s=0;
        int e=n-1;

        //base case array is already sorted
        if (a[s] <= a[e]) return 0;

        while(s<e){
            int m= s+ (e-s)/2;

            //3 4 5 6 7 1 2 mid=3 arr[3](7)>arr[end](2)
            //s=m+1 because we know ans is somewhere to the left of mid
            if(a[m]>a[e]){
                s=m+1;
            }
            //otherwise set end to mid
            else{
                e=m;
            }
        }
        //afer this loop the end will be on the pivot element also the start will also be on this element too
        return e;
    }
    
    //basic binary search code with start and end pointers alredy given
    int bianarysearch(const vector<int>& a,int s,int e, int target){
        while(s<=e){
            int m= s+ (e-s)/2;
            if(a[m]>target){
                e=m-1;
            }
            else if(a[m]<target){
                s=m+1;
            }
            else{
                return m;
            }
        }
        return -1;
    }

    //it checks where the target actually lies and apply binary search there
    int search(vector<int>& a,int target){
        int n=a.size();
        int p=pivotelement(a);
        if (a[p]<=target && target<=a[n-1]){
            return bianarysearch(a,p,n-1,target);
        }
        else{
            return bianarysearch(a,0,p-1,target);
        }
        return -1;
    }
};