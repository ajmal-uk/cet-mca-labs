#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *link;
};

struct node *root = nullptr;

void insterFirst(){
    int item;
    cout<<"Enter the Item to Insert";

    if(!root){
        root->data = item;
        root->link = nullptr;
        return;
    }

    struct node *ptr = new node();
    ptr->data = item;
    root->link = ptr;
    ptr->link = nullptr;
}

void deleteFirst(){
    if(!root){
        cout<<"No Item to Remove";
    }else{
        struct node *temp = root;
        root = root->link;
        free(temp);
    }
}


void traveral(){
    if(!root){
        cout<<"No Item to Remove";
    }else{
        struct node *temp = root;
        while(temp!=nullptr){
            cout<<"| "<< temp->data << " |";
            if(!(temp->link == nullptr)) cout<< "---->"; 
        }
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at First\n";
        cout << "2. Delete First\n";
        cout << "3. Traverse\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insterFirst();
                break;
            case 2:
                deleteFirst();
                break;
            case 3:
                traveral();
                break;
            case 4:
                cout << "Exiting program...\n";
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
