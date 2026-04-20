#include "headers.hpp"
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
    void print_dfs(TreeNode *root){
        if (root == nullptr) return;
        cout<<root->val<<" ";
        print_dfs(root->left);
        print_dfs(root->right);        
    }



    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int depth_left = maxDepth(root->left) + 1;
        int depth_right = maxDepth(root->right) + 1;
        return max(depth_left, depth_right);
    }
};


int main(){
    // vector<int> values = {3,9,20,-200,-200,15,7};
    vector<int> values = {1};
    vector<TreeNode*> node_vec;
    node_vec.reserve(values.size());

    for(int i=0; i<values.size(); i++){
        TreeNode* tn = nullptr;
        if(values[i] != -200)
            tn = new TreeNode(values[i]);
        
        node_vec.push_back(tn);
    }

    TreeNode* root = nullptr;
    if (node_vec.size()> 0)
        root = node_vec[0];

    for(int i=0; i<node_vec.size()/2; i++){
        node_vec[i]->left = node_vec[2*i + 1];
        node_vec[i]->right = node_vec[2*i + 2];
    }

    Solution sol;
    // sol.print_dfs(root);
    cout<<sol.maxDepth(root)<<endl;

    return 0;
}