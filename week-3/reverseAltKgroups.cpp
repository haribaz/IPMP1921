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

node* reverseList(node* head, int k) {
    int count = 0;
    node* current=head;
    node* prev=NULL;
    node* aduthu=NULL;
    while(current != NULL && count < k) {
        aduthu = current->next;
        current->next = prev;
        prev = current;
        current = aduthu;
        count++;
    }
    
    if(head != NULL) {
        head->next = current;
    }
   count = 0;
    while(count < k-1 && current != NULL) {
        current = current->next;
        count++;
    }

    if(current!=NULL) {
        current->next = reverseList(current->next, k);
    }

    return prev;
}


int main() {
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);
    Insert(10);
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);
    Insert(10);
    printList();
    cout<<endl;
    int k = 2;
    head = reverseList(head, k);
    printList();
}