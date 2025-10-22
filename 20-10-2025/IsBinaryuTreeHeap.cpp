#include<bits/stdc++.h>
using namespace std;
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
    //function that counts total no of no nodes in a tree
    int totalNode(Node* r){
        if(r==nullptr)return 0;
        return 1+(totalNode(r->left)+totalNode(r->right));
    }

    //function that checks for heap
    bool bothProperties(Node* r,int i,int t){
        if(r==nullptr)return true;
        if(i>=t)return false;
        //base conditions if our index gets more than or equal to total nodes then its not complete
        if(r->left && r->data<r->left->data)return false;
        if(r->right && r->data<r->right->data)return false;
        //check both the nodes to see it they are greater than their parent and if soo return false

        //recursive call on left and right child with their iundexes 2*r+1 and 2*r+2
        return bothProperties(r->left,2*i+1,t)&&bothProperties(r->right,2*i+2,t);

        //in this method the complteness can only be determined when the tree ius fully parsed
    }
    bool isHeap(Node* r) {
        //call the other functions
        int t=totalNode(r);
        return bothProperties(r,0,t);
    }
};