#include<iostream>
#include<vector> 

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int dfs(TreeNode* root,int& distance)
{
    if(root == nullptr)
        return 0;
    int left = dfs(root->left,distance);
    int right = dfs(root->right,distance);
    distance = max(left+right,distance);
    return max(left,right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int distance = 0;
    dfs(root,distance);
    return distance;
}

int main()
{
	return 0;
}
