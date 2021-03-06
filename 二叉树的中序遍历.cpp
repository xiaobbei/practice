#include<iostream>
#include<vector>

using namespace std; 
vector<int> inorderTraversal(TreeNode* root) {
        // 二叉树遍历，我们只用非递归（递归版本谁不会呢？）
        // 1. 栈后法。即先入栈，再访问。
        // 2. 中序遍历，左臂入栈法。（前序遍历，栈后法+右左孩子入栈法。后序遍历？有点难哦！）
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
            // 每 pop 一个节点，将其右子树做**左臂入栈**操作。
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
