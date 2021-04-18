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

node* reverseList(node *temp) {
        node *current = temp;
        node *prev = NULL;
        node *aduthu = NULL;
        while(current != NULL) {
            aduthu = current->next;
            current->next = prev;
            prev = current;
            current = aduthu;
        }
        temp = prev;
        return temp;
        
    }
    bool isPalindrome() {
        node *slow = head;
        node *fast = head;
        node *prev_slow = head;
        
        if(head != NULL) {
        while(fast!=NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev_slow = slow;
            slow = slow->next;
        }
    }
        prev_slow->next = NULL;
        node* rev = reverseList(slow);
        while(head!=NULL && rev!=NULL) {
            if(head->data != rev->data)
                return false;
            head = head->next;
            rev = rev->next;
        }
        return true;
    }


int main() {
    Insert(2);
    Insert(5);
    Insert(5);
    Insert(2);
    printList();
    cout<<endl;
    if(isPalindrome()){
        cout<<"Palindrome";
    } else {
        cout<<"Not Palindrome";
    };
}