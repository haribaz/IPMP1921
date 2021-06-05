int diff(node* root) {
    if(root == NULL) {
        return 0;

    return root->data - diff(root->left) - diff(root->right);
    }
}