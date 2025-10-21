#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
void heapify(vector<int> &arr,int n,int i){
	int maxi=i;
	int l=2*maxi+1;
	int r=2*maxi+2;
	if(l<n&&arr[maxi]<arr[l]){
		maxi=l;
	}
	if(r<n&&arr[maxi]<arr[r]){
		maxi=r;
	}
	if(maxi!=i){
		swap(arr[i],arr[maxi]);
		heapify(arr,n,maxi);
	}
}
vector<int> buildHeap(vector<int> arr, int n)
{	
	for(int i=n/2;i>=0;i--){
		heapify(arr,n,i);
	}
	return arr;
}