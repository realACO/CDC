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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        //each description vector hase 3 elements one is the value of root, secont is the value of pair, third is the if child is left child of root or not
        unordered_map<int,TreeNode*> n;
        //we maintain n so that we dont need to create nw node everytime
        unordered_set<int> c;
        //c is maintained to find the root node at the end, it stores child nodes, if any nodes from n doesnt appeare in c then its root
        for(auto& i:descriptions){
            int parent=i[0];
            int child=i[1];
            int isLeft=i[2];
            if(!n[parent]){
                //directly create the parent node as we put it inside the map if it doesnt exist
                n[parent]=new TreeNode(parent);
            }
            if(!n[child]){
                //directly create the child node as we put it inside the map if it doesnt exist
                n[child]=new TreeNode(child);
            }
            //linking of parent and child
            if(isLeft){
                n[parent]->left=n[child];
            }else{
                n[parent]->right=n[child];
            }

            //insert child into the set
            c.insert(child);
        }


        TreeNode* root=new TreeNode(-1);

        //check if any nodes of n doesnt appeare in c and store it in root
        for(auto& i:n){
            if(!c.count(i.first)){
                root=i.second;
                break;
            }
        }
        return root;
    }
};