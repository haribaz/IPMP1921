
void leftBoundary(node* root) {
    if(root == NULL) {
        return;
    }
    if(root->left != NULL) {
        cout<<root->data;
        leftBoundary(root->left);
    } else if(root->right != NULL) {
        cout<<root->data;
        leftBoundary(root->right);
    }
}

void leaves(node* root) {
    if(root == NULL) {
        return;
    }
    leaves(root->left);
    if(root->left == NULL && root->right) {
        cout<<root->data;
    }
    leaves(root->right);
}
\
void rightBoundary(node* root) {
    if(root == NULL) {
        return;
    }

    if(root->right != NULL) {
        rightBoundary(root->right);
        cout<<root->data;
    } else if(root->left != NULL) {
        rightBoundary(root->left);
        cout<<root->data;
    }
}




void boundaryTraversal(node* root) {
    cout<<root->data;
    leftBoundary(root->left);
    leaves(root->left);
    leaves(root->right);
    rightBoundary(root->right);
}