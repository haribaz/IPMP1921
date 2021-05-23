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

void merge(node* a, node **b) {
    node *a_curr = a, *b_curr = *b;
    node *a_next, *b_next;

    while(a_curr != NULL && b_curr != NULL) {
        a_next = a_curr->next;
        b_next = b_curr->next;

        a_curr->next = b_curr;
        b_curr->next = a_next;

        a_curr = a_next;
        b_curr = b_next;
    }
    *b = b_curr;
}


int main() {
    struct node* a = NULL;
    struct node* b = NULL;   
    Insert(&a, 2);
    Insert(&a, 8);
    Insert(&a, 6);
    Insert(&a, 1);
    Insert(&a, 10);
    Insert(&b, 7);
    Insert(&b, 4);
    Insert(&b, 6);
    Insert(&b, 5);
    Insert(&b, 10);
    Insert(&b, 55);
    Insert(&b, 77);
    printList(a);
    cout<<endl;
    printList(b);
    cout<<endl;
    merge(a, &b);
    printList(a);
    cout<<endl;
    printList(b);
}