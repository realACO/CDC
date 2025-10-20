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
//NLR
class Solution {
public:
    void helper(TreeNode* r,vector<int>&ans){
        if(r==nullptr)return;
        ans.push_back(r->val);
        helper(r->left,ans);
        helper(r->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* r) {
        vector<int> ans;
        helper(r,ans);
        return ans;
    }
};