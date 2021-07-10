#include <iostream>
using namespace std;
 

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 

int isSumTree(struct node* node, int &flag) 
{
    if(node == NULL) {
        return 0;
    }

    if(node->left == NULL && node->right == NULL) {
        return node->data;
    }
    int ls = isSumTree(node->left, flag);
    int rs = isSumTree(node->right, flag);
    if(node->data != ls+rs) {
        flag = 0;
    }
    return node->data + ls + rs;
}
 
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(
        sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
int main()
{
    struct node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);
     int flag = 1;
     isSumTree(root, flag);
    if (flag)
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";
    return 0;
}