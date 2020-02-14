#include<iostream>
#include<vector>

using namespace std; 
vector<int> inorderTraversal(TreeNode* root) {
        // ����������������ֻ�÷ǵݹ飨�ݹ�汾˭�����أ���
        // 1. ջ�󷨡�������ջ���ٷ��ʡ�
        // 2. ��������������ջ������ǰ�������ջ��+��������ջ��������������е���Ŷ����
        vector<int> res;
        stack<TreeNode*> path;
        while(root) {
            path.push(root);
            root = root->left;
        }
        
        while(!path.empty()) {
            auto node = path.top();
            path.pop();
            res.push_back(node->val);
            // ÿ pop һ���ڵ㣬������������**�����ջ**������
            node = node->right;
            while (node) {
                path.push(node);
                node = node->left;
            }  
        }
        return res;
    }

int main()
{
	return 0;
}
