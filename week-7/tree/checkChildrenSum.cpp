int isSumProperty(Node *root)
{
   if(root == NULL || (root->left ==NULL && root->right == NULL)) {
       return 1;
   }
   
   int left=0, right=0;
   if(root->left != NULL) {
       left = root->left->data;
   }
   
   if(root->right != NULL) {
       right = root->right->data;
   }
   
   if(root->data == left+right && isSumProperty(root->left) && isSumProperty(root->right)) {
       return 1;
   }
   return 0;
   
}