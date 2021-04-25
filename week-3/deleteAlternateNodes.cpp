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

void removeAlternate() {
        node* curr = head;
        node* del = head->next;

        while(curr!=NULL && del!=NULL) {
            curr->next = del->next;
            free(del);
            curr = curr->next;
            if(curr!=NULL) {
                del = curr->next;
            }
        }
     
}

int main() {
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);
    Insert(10);
    printList();
    cout<<endl;
    removeAlternate();
    printList();
}