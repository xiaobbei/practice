#include<iostream>

using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr || val == root->val)
            return root;
        return root->val > val ? searchBST(root->left,val):searchBST(root->right,val);
}

int main()
{
	
}
