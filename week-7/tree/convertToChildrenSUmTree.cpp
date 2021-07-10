void convert(TreeNode* root) {
    if(root==NULL || (root->left==NULL && root->right == NULL)) {
        return;
    }
    int left=0, right=0;
    convert(root->left);
    convert(root->right);

    if(root->left != NULL) {
        left = root->left->data;
    }

    if(root->right != NULL) {
        right = root->right->data;
    }

    int diff = left + right - root->data;
    if(diff>0) {
        root->data += diff;
    }

    if(diff<0) {
        increment(root, -diff);
    }
}

void increment(TreeNode *root, int diff) {
    if(node->left != NULL) {
        node->left->data += diff;
        increment(node->left, diff);
    } else if(node->right != NULL) {
        node->right->data += diff
        increment(node->right, diff);
    }
}