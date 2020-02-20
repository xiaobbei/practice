#include<queue>
Queue *shortTree(Tree *root)
{
	std::queue<Tree *>q;
	if(root==NULL)
	{
		return NULL;
	}
	q.push(root);			//	�Ƚ�ͷ������
	q.pop();					//��ͷ���ȡ��
	while(!q.empty())
	{
		Tree *front = q.front();		//���׽��ȡ��
		printf("%c",front->val);		//��ӡ�׽��
		if(front->left !=NULL)		//������Ӳ�ΪNULL����������
		{
			q.push(front->left);
		}
		if(front->left !=NULL)		//����Һ��Ӳ�ΪNULL����������
		{
			q.push(front->right);
		}
	}
}
