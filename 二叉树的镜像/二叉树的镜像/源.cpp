#include<iostream>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

//½»»»×óÓÒ×ÓÊ÷

void Mirror(TreeNode *pRoot) {
	if (pRoot == nullptr)
		return;
	TreeNode* temp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = temp;
	Mirror(pRoot->left);
	Mirror(pRoot->right);
}

int main()
{

	system("pause");
	return 0;
}