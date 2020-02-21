#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//[begin,i)与(i,end],分别构造左右子树
vector<TreeNode*> Tree(int begin, int end) //创建二叉搜索树
{
	vector<TreeNode*> res;
	if (begin > end) //表示该区间没有子树
	{
		res.push_back(nullptr);
		return res;
	}
	for (int i = begin; i <= end; ++i)
	{
		vector<TreeNode*> leftTree = Tree(begin, i - 1); //分别构造左子树与右子树
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
