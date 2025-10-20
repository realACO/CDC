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
    // this function returns height of current subtree
    int parse(TreeNode* root,int &dm){
        if(root==nullptr)return 0;

        //calculates left height and right of a a tree
        int l=parse(root->left,dm);
        int r=parse(root->right,dm);
        //store the max diameter(l+r) in dm
        dm=max(dm,l+r);

        //pass the height to their parent element
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dm=0;
        parse(root,dm);
        return dm;
    }
};