class Solution {
  public:
  
    int toSumTree(Node *root)
    {
        if(root == NULL) {
            return 0;
        }
        int temp = root->data;
        root->data = toSumTree(root->left) + toSumTree(root->right);
        return temp + root->data;
    }
};