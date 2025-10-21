#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool canBePlaced(vector<int> &arr,int cows,int dist){
        //initially one cow is placed, base condn total cows wil alws be greater than equal to 1
        int cowcnt=1;

        //we will start by placing the cow at first index of array
        int last=arr[0];
        for(int i=1;i<arr.size();i++){
            // then we will check thatthe dist between arr[i] and arr[last placed cow position] if it is greater than equal to dist we increase the cowcnt and update last
            if(arr[i]-last>=dist){
                cowcnt++;
                last=arr[i];
            }
            //after each i teration we check if the cowcnt is greater than total cows and if so we return true
            if(cowcnt>=cows)return true;
        }

        //cowcnt not greater than totalcows we cant place all the cows so return false
        return false;
    }

    //task is to place the cows in stall position denoted by the value inside vector such that the min distance of all psbl placemenet's of cows is maximmum
    //in short max of mim
    int aggressiveCows(vector<int> &s, int k) {
        sort(s.begin(),s.end());
        //first we sort the array
        int st=0;
        int e=s[s.size()-1]-s[0];
        //our seachspace of answer will be betwen the 0 and the max posible distance between any two cows which will be last element of aray - first element of array
        while(st<=e){
            int m=st+(e-st)/2;

            //we check if we can place k cows at the min distance of m between them, if so we move sto one place ahead m
            if(canBePlaced(s,k,m)){
                st=m+1;
            }
            //else we move e to m-1
            else{
                e=m-1;
            }
        }
        //return e because at the end of the while loop e wil be sitting on top of the answer
        return e;
    }
};