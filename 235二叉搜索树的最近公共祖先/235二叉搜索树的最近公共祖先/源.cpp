#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

//根据二叉搜索树的性质，left比root的值小，right比root的值大
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == nullptr)
		return nullptr;
	if (root->val>p->val&&root->val<q->val)
		return root;
	if (root->val<p->val&&root->val<q->val)
		return lowestCommonAncestor(root->right, p, q);
	if (root->val>p->val && root->val>q->val)
		return lowestCommonAncestor(root->left, p, q);
	return root;
}
int main()
{
	system("pause");
	return 0;
}