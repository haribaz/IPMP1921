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

node* Un(node* a, node* b) {
    unordered_map<int, int> map1;
    node *result = NULL;
    while(a!=NULL) {
        map1[a->data]++;
        a=a->next;
    }

    while(b!=NULL) {
        map1[b->data]++;
        b=b->next;
    }
    for(auto x: map1) {
        Insert(&result, x.first);
    }
    return result;

}


node* In(node* a, node* b) {
    unordered_map<int, int> map1;
    node *result = NULL;
    while(a!=NULL) {
        map1[a->data]++;
        a=a->next;
    }

    while(b!=NULL) {
        if(map1.find(b->data) != map1.end()) {
            Insert(&result, b->data);
        }
        b=b->next;
    }
    return result;

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
    printList(a);
    cout<<endl;
    printList(b);
    cout<<endl;
    node* un = Un(a, b);
    printList(un);
    cout<<endl;
    node* in = In(a, b);
    printList(in);
    
}