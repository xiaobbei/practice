vector<int> preorderTraversal(TreeNode* root) {
       stack<TreeNode*> st;
       vector<int> res;
       while(root != nullptr ||!st.empty())
       {
           while(root)
           {
               st.push(root->right);
               res.push_back(root->val);
               root = root->left;
           }
           root = st.top();
           st.pop();
       } 
       return res;
}
