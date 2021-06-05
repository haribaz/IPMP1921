void k(node* root, int k) {
    if(root == NULL) {
        return;
    }

    if(k==0) {
        cout<<root->data;
        return;
    }

    k(root->left, k-1);
    k(root->right, k-1);
}