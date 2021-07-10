#include <bits/stdc++.h>
using namespace std;
 
class node {
public:
    int data;
    node* left;
    node* right;
};
 
bool IsFoldableUtil(node* n1, node* n2);
 
/* Returns true if the given tree can be folded */
bool IsFoldable(node* root)
{
    if (root == NULL) {
        return true;
    }
 
    return IsFoldableUtil(root->left, root->right);
}
 
bool IsFoldableUtil(node* n1, node* n2)
{
    if (n1 == NULL && n2 == NULL) {
        return true;
    }
 
    if (n1 == NULL || n2 == NULL) {
        return false;
    }
 

    return IsFoldableUtil(n1->left, n2->right) && IsFoldableUtil(n1->right, n2->left);
}
 

node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return (Node);
}

int main(void)
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
 
    if (IsFoldable(root) == true) {
        cout << "Tree is foldable";
    }
    else {
        cout << "Tree is not foldable";
    }
 
    return 0;
}