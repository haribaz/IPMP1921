void doubleTree(node* root) {
    if(root == NULL) {
        return;
    }

    doubleTree(node->left);
    doubleTree(node->right);

    node* oldLeft = node->left;
    node->left = newNode(node->data);
    node->left->left = oldLeft;
}