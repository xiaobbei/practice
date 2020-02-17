#include<iostream>

using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* searchBST(TreeNode* root, int val) {
    while(true)
	{
		if(root == nullptr || root->val == val)
			return root;
		root = root->val>val?root->left:root->right;	
	} 
}

int main()
{
	
}
