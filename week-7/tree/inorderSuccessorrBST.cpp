node* helper(node* root, node* current) {
    if(current == NULL) {
        return NULL;
    }

    if(current->right != NULL) {
        node* temp = current->right;
        while(temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    } else {
        node* successor = NULL;
        node* ancestor = root;
        while(ancestor != current) {
            if(ancestor->data > current->daya) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}