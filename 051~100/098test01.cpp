void verify(TreeNode* root, long long lower, long long upper,bool & sol)
{
    if(root==nullptr) return;
    else if(root->val>=upper){sol=false;return;}
    else if(root->val<=lower){sol=false;return;}
    verify(root->right,root->val,upper,sol);
    verify(root->left,lower,root->val,sol);
}

bool isValidBST(TreeNode* root) {
    bool sol=true;
    if(root==nullptr) return sol;
    verify(root,LLONG_MIN,LLONG_MAX,sol);
    return sol;

}
