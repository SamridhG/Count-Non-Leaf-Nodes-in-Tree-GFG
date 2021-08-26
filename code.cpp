class Solution {
  public:
  vector<int>A;
  void   countnode(Node *root)
  {
      if(root!=NULL)
      {
          A.push_back(root->data);
          countnode(root->left);
          countnode(root->right);
      }
  }
  void countleaf(Node *root,int &leaf_node)
  {
      if(root!=NULL)
      {
          if(root->left==NULL && root->right==NULL)
          {
              leaf_node++;
          }
          else
          {
              countleaf(root->left,leaf_node);
              countleaf(root->right,leaf_node);
          }
      }
  }
    int countNonLeafNodes(Node* root) {
        // Code here
        
        int leaf_node=0;
        countnode(root);
        int total_node=A.size();
        A.clear();
        countleaf(root,leaf_node);
        return total_node-leaf_node;
    }
};
