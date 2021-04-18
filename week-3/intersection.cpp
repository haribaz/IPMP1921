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

node* Intersect(node* a, node* b) {
    node* temp = NULL;
    while(a!=NULL && b!=NULL) {
        if(a->data == b->data) {
            Insert(&temp, a->data);
            a = a->next;
            b = b->next;
        } else if(a->data < b->data) {
            a = a->next;
        } else {
            b = b->next;
        }
    }
    return temp;
}

int main() {
    struct node* a = NULL;
    struct node* b = NULL;   
    Insert(&a, 2);
    Insert(&a, 4);
    Insert(&a, 6);
    Insert(&a, 8);
    Insert(&a, 10);
    Insert(&b, 1);
    Insert(&b, 4);
    Insert(&b, 6);
    Insert(&b, 7);
    Insert(&b, 10);
    printList(a);
    cout<<endl;
    printList(b);
    cout<<endl;
    node* temp = Intersect(a, b);
    printList(temp);
    
}