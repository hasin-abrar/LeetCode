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

    void get_leaf_nodes(TreeNode* root, vector<int>& vec){
        if(root == nullptr) return;
        if(root->left==nullptr && root->right == nullptr)
            vec.push_back(root->val);
        get_leaf_nodes(root->left, vec);
        get_leaf_nodes(root->right, vec);
    }

    void print_vec(vector<int> vec){
        for(auto v: vec) cout<<v<<" ";
        cout<<"\n";
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1_leaf_vec, t2_leaf_vec;
        get_leaf_nodes(root1, t1_leaf_vec);
        get_leaf_nodes(root2, t2_leaf_vec);
        print_vec(t1_leaf_vec);
        print_vec(t2_leaf_vec);
        if(t1_leaf_vec.size() != t2_leaf_vec.size()) return false;
        for(int i=0; i<t1_leaf_vec.size(); i++){
            if(t1_leaf_vec[i]!= t2_leaf_vec[i]) return false;
        }
        return true;
    }
};

TreeNode* get_tree_root(vector<int> &values){
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
    return root;
}


int main(){
    vector<int> v1 = {3,9,20,-200,-200,7,15};
    vector<int> v2 = {3,9,20,-200,-200,15,7};
    TreeNode* r1 = get_tree_root(v1);
    TreeNode* r2 = get_tree_root(v2);
    
    Solution sol;
    if(sol.leafSimilar(r1, r2)){
        cout<<"Similar\n";
    }
    else{
        cout<<"Not similar\n";
    }
    
    

    return 0;
}