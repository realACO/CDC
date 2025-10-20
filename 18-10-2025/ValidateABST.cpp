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
//a recursive function that checks if a value of node is between minval and maxval
    bool helper(TreeNode* r,long minVal, long maxVal){
        if(r==nullptr)return true;
        if(r->val<=minVal||r->val>=maxVal){
            return false;
        }

        //when we go left then we know the max value of left subtree cant be greater that value of node
        //similarly when we go right we know that the value of right subtree cant gl less that value of node
        return helper(r->left,minVal,r->val)&&helper(r->right,r->val,maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
};