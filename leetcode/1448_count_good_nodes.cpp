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

    int get_count(TreeNode* root, int max_so_far){
        if(root == nullptr) return 0;
        int count = (root->val >= max_so_far) ? 1: 0;
        max_so_far = max(max_so_far, root->val);
        return get_count(root->left, max_so_far) + 
            get_count(root->right, max_so_far) + count;
    }

    int goodNodes(TreeNode* root) {
        return get_count(root, root->val);
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
    vector<int> vec = {3};
    TreeNode* root = get_tree_root(vec);
    
    Solution sol;
    
    cout<<sol.goodNodes(root)<<endl;
    

    return 0;
}