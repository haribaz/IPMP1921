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

void splitList() {
   if(head==NULL)
        {
            return head;
        }
        ListNode* l1=head;
        ListNode* l2=head->next;
        ListNode* l3=head->next;
        while(l1->next!=NULL && l2->next!=NULL)
        {
            l1->next=l1->next->next;
            l2->next=l2->next->next;
            l1=l1->next;
            l2=l2->next;
            
        }
        l1->next=l3;
        return head;
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
    splitList();
    printList();
}