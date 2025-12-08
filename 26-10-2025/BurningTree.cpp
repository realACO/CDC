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
  private:
    Node* find(Node* r, int target){
        if(r==nullptr)return nullptr;
        if(r->data==target)return r;
        Node* temp=find(r->left,target);
        if(temp)return temp;
        return find(r->right,target);
    }
  public:
    int minTime(Node* root, int target) {
        unordered_map<Node*,Node*> parent;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            if(t->left){
                parent[t->left]=t;
                q.push(t->left);
            }
            if(t->right){
                parent[t->right]=t;
                q.push(t->right);
            }
        }
        
        Node* temp=find(root,target);
        
        queue<pair<Node*,int>> burning;
        unordered_map<Node*,int> visited;
        
        burning.push({temp,0});
        visited[temp]=1;
        int timer;
        while(!burning.empty()){
            auto t=burning.front();
            burning.pop();
            Node* n=t.first;
            int time=t.second;
            if(parent.count(n) && !visited[parent[n]]){
                burning.push({parent[n],time+1});
                visited[parent[n]]=1;
            }
            if(n->left && !visited[n->left]){
                burning.push({n->left,time+1});
                visited[n->left]=1;
            }
            if(n->right && !visited[n->right]){
                burning.push({n->right,time+1});
                visited[n->right]=1;
            }
            timer=time;
        }
        return timer;
    }
};