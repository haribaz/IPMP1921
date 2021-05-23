#include <bits/stdc++.h>
using namespace std;
  
struct Node {
    int data;
    struct Node* next;
};
  

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
  
  
  
void skipMdeleteN(Node *head, int M, int N) {
    Node* temp = head, *del;
    int count = 0;
    while(temp != NULL) {
            for(count = 1; count<M && temp!=NULL; count++) {
                temp = temp->next;
            }

            if(temp == NULL) {
                return;
            }
            del = temp->next;
            for(count = 1; count <= N && del!=NULL; count++) {
                Node *t = del;
                del = del->next;
                free(t);
            }
            temp->next = del;
            temp = del;
    }
}




int main()
{
    struct Node* head = NULL;
    for (int i = 8; i >= 1; i--)
        push(&head, i);
  
    cout << "Original Linked List: ";
    printList(head);
    skipMdeleteN(head, 2, 2);
    printList(head);

    return 0;
}
