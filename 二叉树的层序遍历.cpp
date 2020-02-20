#include<queue>
Queue *shortTree(Tree *root)
{
	std::queue<Tree *>q;
	if(root==NULL)
	{
		return NULL;
	}
	q.push(root);			//	先将头结点放入
	q.pop();					//将头结点取出
	while(!q.empty())
	{
		Tree *front = q.front();		//将首结点取出
		printf("%c",front->val);		//打印首结点
		if(front->left !=NULL)		//如果左孩子不为NULL，则放入队列
		{
			q.push(front->left);
		}
		if(front->left !=NULL)		//如果右孩子不为NULL，则放入队列
		{
			q.push(front->right);
		}
	}
}
