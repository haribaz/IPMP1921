#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

struct node* head = NULL;

void Insert(int data) {
    node *temp = new node();
    temp->data = data;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
        return;
    }
    node *temp1 = head;
    while(temp1->next != NULL) {
        temp1=temp1->next;
    }
    temp1->next = temp;
}

void printList() {
    node *temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void reverseList (node* head) {
    if(head == NULL) {
        return;
    }
    reverseList(head->next);
    cout<<head->data<<" ";
 }


int main() {
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);
    printList();
    cout<<endl;
    reverseList(head);
}