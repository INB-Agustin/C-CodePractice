#include <iostream>
using namespace std;

struct Node{
    int value; //data member
    Node *next; //pointer to next node
} *head = NULL, *current, *previous, *nextNode;

//Node *head =NULL, current, previous;

void appendNode(int );
void displayList();
void insertNode(int);
void deleteNode(int);
void destroyList();
int main(){

    int val;

    do{
        cout << "Enter a value [-1 to end input]" << endl;
        cin >> val;
        
        if (val < 0){
            break;
        }
        insertNode(val);

    }while(true);
    displayList();

    while (true){
        cout << "Enter a value to be deleted: ";
        cin >> val;
        if (val < 0)  {
            break;
        }
        deleteNode(val);
        displayList();
    }
    destroyList();
    displayList();
    

    return 0;
}

void appendNode(int newValue){
    Node *newNode = new Node; //create a new node
    newNode->value = newValue;
    newNode->next = NULL;

    if (head == NULL){// if the list is empty
        head = newNode;    
    }else{// if the list is not empty
            //traverse the list
        current = head;
        while (current->next != NULL){
            current = current->next;
        }
        // fi the last node is already reached, append the new node
        current->next = newNode;
    }
    cout << "The new node is appended.... \n";
}

void displayList(){
    if (head == NULL){// if the list is empty
        cout << "The list is empty" << endl;
    }else {
        cout << "\n Display all Values... \n";
        //Traverse the list up to the last node
        current = head;
        while(current != NULL){
            cout << current->value << endl;
            current = current->next;
        }
        cout << "\n End of the List... \n";
}
}

void insertNode(int newValue){
    Node *newNode = new Node; //create a new node
    newNode->value = newValue;
    newNode->next = NULL;

    if (head == NULL){// if the list is empty
        head = newNode;
    }else {
        //Traverse
        current = head;
        previous = NULL;
        //Loop will stop if the new value is lesser than the current node
        // or the end of the list is reached
        // < sort ascending order
        // > sort descending order
        while (current != NULL&& current-> value < newValue ){  
            previous = current;
            current = current -> next;
        }
        if(previous ==NULL){
            //make the new node as the first in the list
            head = newNode;
            newNode->next = current;
        }else{
            //Insert the new node
            //Break the link so that the new node can be inserted
            previous-> next = newNode;
            //reconnet the list
            newNode->next = current;
        }

        
    }
    cout << "The new node is inserted.... \n";
}

void deleteNode(int valueToDelete){
    bool found = false;
    if (head == NULL){
        cout << "This is Empty" << endl;
    }else{
        if (head->value == valueToDelete){
            //if 
            current = head->next;
            delete head;
            head  = current;
            found = true;
        }else{
            //Traverse the list until the value to be deleted is found
            current = head;
            previous = NULL;
            while(current ->value != valueToDelete){
                previous = current;
                current = current ->next;

            }
            if (current != NULL){
                previous->next = current->next;
                delete current;
                found = true;
            }
        }
        if (found){
            cout << "The node is deleted.... \n";
        }else{
            cout << "The node is not found.... \n";
        }
    }
}

void destroyList(){
    if (head == NULL){
        cout << "This is Empty" << endl;
    }else{
        current = head;
        while (current != NULL){
            nextNode = current ->next;
            delete current;
            current = nextNode;
        }
        cout << "The List is now Destroyed.... \n";
        head = NULL;
    }
}