void deleteTree(node* root) {
    if(root == NULL) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete root;
}