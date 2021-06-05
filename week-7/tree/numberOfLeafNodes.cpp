#include <bits/stdc++.h>
using namespace std;
  
int counti = 0;
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  

void getLeafCount(struct node* node) 
{ 
    if(node == NULL)     
        return; 
         getLeafCount(node->left);
    if(node->left == NULL && node->right == NULL) 
          counti++;     
         getLeafCount(node->right); 
} 
  

struct node* newNode(int data) 
{ 
    struct node* node = (struct node*) 
                    malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
      
return(node); 
} 
  

int main() 
{ 
  
    struct node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
      
getLeafCount(root);
cout << "Leaf count of the tree is : "<<counti<< endl; 
return 0; 
} 