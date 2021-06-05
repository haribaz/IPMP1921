void minNode(node* root) {
    node* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    cout<<temp->data;
}