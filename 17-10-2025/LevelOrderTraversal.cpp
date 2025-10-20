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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //ans will be stored here
        vector<vector<int>> ans;

        //edge case
        if(root==nullptr)return ans;

        //we will use queue for level order traversal
        queue<TreeNode*> q;

        q.push(root);
        q.push(nullptr);
        //initially push root and a nullptr to the queue

        vector<int> l;
        //l will strore values of a level it will clear itself when nullptr;s are founf, nullptrs will act as a seperator between each level
        while(!q.empty()){

            TreeNode* temp=q.front();
            q.pop();
            //store first element in temp and and pop it

            //if it is nullptr then one level is finished and we need to push it inside our ans vector, clear l after we push
            //if after that operation q isnt empty then push another nullptr as a seperator for upconmming elements
            if(temp==nullptr){
                ans.push_back(l);
                l.clear();
                if(!q.empty()){
                    q.push(nullptr);
                }
            }

            else{
                //if it is not nullptr we need to push val of temp inside l and push the child of temp inside queue
                l.push_back(temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        return ans;
    }
};