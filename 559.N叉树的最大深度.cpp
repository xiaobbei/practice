#include<iostream>

using namespace std;

class Node
{
	int val;
	vector<Node*> children;
	
	Node()
	{}
	
	Node(int _val,vector<Node*> _children)
	{
		val = _val;
		children = _children;
	}
};

int MaxDepth(Node* root)
{
	if(root == nullptr)
		return 0;
	int count = 0;
	for(auto it:root->children)
	{
		count = max(count,MaxDepth(it));
	}
	return ++count;
}

int main()
{

	return 0;
}
