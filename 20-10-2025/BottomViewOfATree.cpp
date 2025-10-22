#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
    vector<int> bottomView(Node *r) {
        if(r==nullptr)return {};
        queue<pair<Node*,int>> q;
        map<int,int> m;
        q.push({r,0});
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int t=a.second;
            Node* temp=a.first;
            m[t]=temp->data;//exact same as top view only change is this line, we rewrite all the key of same vertical line till final node making all the stored element in map
            if(temp->left)q.push({temp->left,t-1});
            if(temp->right)q.push({temp->right,t+1});
        }
        vector<int> ans;
        for(auto i:m){
            ans.push_back(i.second);
            
        }
        return ans;
    }
};