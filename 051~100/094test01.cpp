void inorderhelp(TreeNode *root,vector<int>&sol)
{
    if(root==nullptr) return;
    inorderhelp(root->left,sol);
    sol.push_back(root->val);
    inorderhelp(root->right,sol);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> sol;
    inorderhelp(root,sol);
    return sol;
}
