int firstLeafLevel = 0 //global

bool check(node* root, level) {
    if(root == NULL) {
        return true;
    }

    if(root->left == NULL && root->right == NULL) {
        if(firstLeafLevel == 0) {
            firstLeafLevel = level;
            return true;
        } else {
            return level == firstLeafLevel;
        }
    }

    return check(root->left, level+1) && check(root->right, level+1);
}