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
//LRN
class Solution {
public:
    void helper(TreeNode* r,vector<int>&ans){
        if(r==nullptr)return;
        helper(r->left,ans);
        helper(r->right,ans);
        ans.push_back(r->val);
    }
    vector<int> postorderTraversal(TreeNode* r) {
        vector<int> ans;
        helper(r,ans);
        return ans;
    }
};