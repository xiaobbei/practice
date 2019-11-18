#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	if (vin.size() == 0)
		return nullptr;

	TreeNode* root = new TreeNode(pre[0]);
	vector<int> PL, PR, VL, VR;
	int flag = 0;
	for (int i = 0; i < vin.size(); ++i)
	{
		if (vin[i] == pre[0])
		{
			flag = i;
			break;
		}
	}

	for (int i = 0; i < flag; ++i)
	{
		PL.push_back(pre[i + 1]);
		PR.push_back(vin[i]);
	}
	for (int i = flag + 1; i < vin.size(); ++i)
	{
		VL.push_back(pre[i]);
		VR.push_back(vin[i]);
	}
	root->left = reConstructBinaryTree(PL, PR);
	root->right = reConstructBinaryTree(VL, VR);
	return root;
}

void PreOrder(TreeNode* root)
{
	if (root)
	{
		
		PreOrder(root->left);
		PreOrder(root->right);
		cout << root->val << " ";
	}
}
int main()
{
	int a[] = { 1,2,4,7,3,5,6,8 };
	int b[] = { 4,7,2,1,5,3,8,6 };
	vector<int> p(a, a + sizeof(a) / sizeof(a[0]));
	vector<int> v(b, b + sizeof(b) / sizeof(b[0]));
	TreeNode * root = reConstructBinaryTree(p, v);
	PreOrder(root);
	system("pause");
	return 0;
}