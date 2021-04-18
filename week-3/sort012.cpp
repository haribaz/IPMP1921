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

void sortList() {
   int count[3] = {0, 0, 0}; 
    node *ptr = head; 
  
    while (ptr != NULL) 
    { 
        count[ptr->data] += 1; 
        ptr = ptr->next; 
    } 
  
    int i = 0; 
    ptr = head; 

    while (ptr != NULL) 
    { 
        if (count[i] == 0) 
            ++i; 
        else
        { 
            ptr->data = i; 
            --count[i]; 
            ptr = ptr->next; 
        } 
    }
}


int main() {
    Insert(1);
    Insert(0);
    Insert(1);
    Insert(2);
    Insert(1);
    Insert(0);
    Insert(1);
    Insert(2);
    printList();
    cout<<endl;
    sortList();
    printList();
}