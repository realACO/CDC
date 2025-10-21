#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0];
        int maxprofit=0;
        //basic concept find min of array and subtract it from the max number comming after the array
        //optimised wayis to use a single loop, store min at each iteration and store max of current index elemnt-min
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min){
                min=prices[i];
            }
            int profit=prices[i]-min;
            if(profit>maxprofit){
                maxprofit=profit;
            }
        }
        return maxprofit;
    }
};