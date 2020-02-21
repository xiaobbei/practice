#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//[begin,i)��(i,end],�ֱ�����������
vector<TreeNode*> Tree(int begin, int end) //��������������
{
	vector<TreeNode*> res;
	if (begin > end) //��ʾ������û������
	{
		res.push_back(nullptr);
		return res;
	}
	for (int i = begin; i <= end; ++i)
	{
		vector<TreeNode*> leftTree = Tree(begin, i - 1); //�ֱ�����������������
		vector<TreeNode*> rightTree = Tree(i + 1, end);
		for (auto l : leftTree)
		{
			for (auto r : rightTree)
			{
				TreeNode* root = new TreeNode(i); 
				root->left = l;
				root->right = r;
				res.push_back(root);
			}
		}
	}
	return res;

}
vector<TreeNode*> generateTrees(int n) {
	if (n == 0)
		return vector<TreeNode*>{};
	return Tree(1, n); 
}
int main()
{

	system("pause");
	return 0;
}
