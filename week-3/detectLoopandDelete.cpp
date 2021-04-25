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

bool detectLoop() {
      unordered_set<node*> set;
      node* temp = head;
      node* prev_temp = head;
      while(temp != NULL) {
          if(set.find(temp) != set.end()) {
              prev_temp->next = NULL;
              return true;
          }
          set.insert(temp);
          prev_temp = temp;
          temp = temp->next;
      }
      return false;
}

int main() {
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);
    printList();
    head->next->next->next->next = head->next;
    cout<<endl;
    if(detectLoop()) {
        cout<<"Loop Found";
    } else {
        cout<<"Loop not found";
    }
    cout<<endl;
    if(detectLoop()) {
        cout<<"Loop Found";
    } else {
        cout<<"Loop not found";
    }
}