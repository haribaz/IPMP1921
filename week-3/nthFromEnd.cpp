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

void fromEnd(int n) {
       node *temp = head;
       int count = 0;
       while(temp!=NULL) {
           temp = temp->next;
           count++;
       }

       if(count < n) {
           cout<<"no such node";
           return;
       }
       int i;
       temp = head;
       for (i = 1; i < count - n + 1; i++)
        temp = temp->next;
       cout<<temp->data;
       return;
}

int main() {
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);
    printList();
    cout<<endl;
    int n; 
    cout<<"enter n"<<endl;
    cin>>n;
    fromEnd(n);
}