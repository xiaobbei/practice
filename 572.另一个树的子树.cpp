#include<iostream>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

using namespace std;
bool IsSub(TreeNode* s,TreeNode* t)
{
	if(s == nullptr && t == nullptr)
		return true;
	if(s == nullptr || t === nullptr)
		return false;
	return s->val == t->val && IsSub(s->left,t->left) && IsSub(s->right,t->right); 
}

bool isSubtree(TreeNode* s,TreeNode* t)
{
	if(s == nullptr)
		return false;
	return isSubtree(s->left,t) || isSubtree(s->right,t) || IsSub(s,t);
}

int main()
{
	return 0;
}
