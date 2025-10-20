#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
//do the level order traversal but whenever you encounter nullptr push temp into ans vector
    vector<int> rightSideView(TreeNode* r) {
        vector<int> ans;
        if(r==nullptr)return ans;
        queue<TreeNode*> q;
        q.push(r);
        q.push(nullptr);
        TreeNode* temp=nullptr;
        TreeNode* prev=nullptr;
        while(!q.empty()){
            prev=temp;
            temp=q.front();
            q.pop();
            if(temp==nullptr){
                ans.push_back(prev->val);
                if(!q.empty()){
                    q.push(nullptr);
                }
            }
            else{
                if(temp->left!=nullptr){
                    q.push(temp->left);
                }
                if(temp->right!=nullptr){
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};