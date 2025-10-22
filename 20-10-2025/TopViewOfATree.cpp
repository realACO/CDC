#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    vector<int> topView(Node *r) {
        if(r==nullptr)return {};
        queue<pair<Node*,int>> q;//queue will store the pointer to the node and the line in which it is root of tree is at 0 line as we go left line decrements and as we go right line increments
        map<int,int> m;//map willstore thr first occurences of elements belongint=g to a line , <line,value>
        q.push({r,0});//initially push root node and 0 to queue
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int t=a.second;
            Node* temp=a.first;
            //assign value of queue to t and temp
            if(!m.count(t))m[t]=temp->data;//if map doesnt have t in it we will create a new key t with valur temp->value
            if(temp->left)q.push({temp->left,t-1});//we will push left and right of temp with their respective line values in it
            if(temp->right)q.push({temp->right,t+1});
        }

        //asembling the answer, map by default stores in sorted order of key so the first key in our map belong to leftmost node of tree
        vector<int> ans;
        for(auto i:m){
            //we pust back the value of it in ans
            ans.push_back(i.second);
            
        }
        return ans;
    }
};