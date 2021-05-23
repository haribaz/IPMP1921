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
    Insert(&a, 2);
    Insert(&a, 8);
    Insert(&a, 6);
    Insert(&a, 1);
    Insert(&a, 10);
    Insert(&a, 7);
    Insert(&a, 4);
    Insert(&a, 6);
    Insert(&a, 5);
    Insert(&ab, 10);
    Insert(&a, 55);
    Insert(&a, 77);
    printList(a);
    cout<<endl;
    mergeSort(&a);
    printList(a);
}