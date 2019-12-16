#include<iostream>
#include<vector> 

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> v;
void Tree(TreeNode* root)
{
    if(root == nullptr)
        return ;
    v.push_back(root->val);
    Tree(root->left);
    Tree(root->right);
}
void conver(TreeNode*& root)
{
    if(root == nullptr)
        return ;
    int temp = root->val;
    for(int i = 0;i<v.size();++i)
    {
        if(temp<v[i])
            root->val+=v[i];
    }
    conver(root->left);
    conver(root->right);
}
TreeNode* convertBST(TreeNode* root) {
    Tree(root);
    conver(root);
    return root;
}

int main()
{
	return 0;
}
