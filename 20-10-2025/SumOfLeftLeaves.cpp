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
    //basic function to check if the leaf is left leaf or not
    bool isLeaf(TreeNode* node){
        return node!=nullptr&&node->left==nullptr&&node->right==nullptr;
    }

    //recursively go to each node 
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(root==nullptr)return 0;
        if(isLeaf(root->left))sum+=root->left->val;
        sum+=sumOfLeftLeaves(root->left);
        sum+=sumOfLeftLeaves(root->right);
        return sum;
    }
};