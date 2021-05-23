#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

void Insert(node** head, int data) {
    node *temp = new node();
    temp->data = data;
    temp->next = NULL;
    if(*head == NULL) {
        *head = temp;
        return;
    }
    node *temp1 = *head;
    while(temp1->next != NULL) {
        temp1=temp1->next;
    }
    temp1->next = temp;
}

void printList(node* head) {
    node *temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

pair<node*, node*> alternatingSublists(node* head) {
      node* a = head;
      node* b = head->next;
      node* temp1 = a;
      node* temp2 = b;
      
      while(temp1->next != NULL && temp2->next != NULL) {
          temp1->next = temp1->next->next;
          temp2->next = temp2->next->next;
          temp1 = temp1->next;
          temp2 = temp2->next;
      }
      return {a, b};
}



int main() {
    struct node* head = NULL;
    
    Insert(&head, 2);
    Insert(&head, 8);
    Insert(&head, 6);
    Insert(&head, 1);
    Insert(&head, 10);
    Insert(&head, 7);
    Insert(&head, 4);
    Insert(&head, 6);
    Insert(&head, 9);
    printList(head);
    cout<<endl;
    pair<node*, node*> p = alternatingSublists(head);
    printList(p.first);
    cout<<endl;
    printList(p.second);
    
}