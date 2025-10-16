#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int data){
        val=data;
        next=nullptr;
    }
};
bool Search(Node* h,int target){
    while(h){
        if(h->val==target)return true;
        h=h->next;
    }
    return false;
}
bool Search2(Node* h, int target){
    if(h==nullptr)return false;
    if(h->val==target)return true;
    return Search2(h->next,target);
}
int main(){
    Node* h=new Node(5);
    h->next=new Node(8);
    h->next->next=new Node(4);
    h->next->next->next=new Node(3);
    h->next->next->next=new Node(9);
    h->next->next->next->next=new Node(10);
    h->next->next->next->next->next=new Node(6);
    cout<<Search(h,102);
    cout<<Search2(h,6);
}