/*
CS 2413
 LAB – 3
Doubly Linked List


1.	Turn the singly linked list you created in the last lab into a doubly linked list. Implement all of the same functions, but this time with a next and a prev pointer along with a variable int size, to keep a track of number of elements in the list. In addition, also define two functions: void insertAtPos(int pos, int value) and void deleteAtPos(int pos) – to insert and delete a node at the specified position (pos). You may need to check if the node exists at the position passed as argument. If not, then display an error message. Otherwise perform the insertion/deletion at the specified position. 
      [10 points]

//DLList.h
class Node
{
  private:
      int info;

  public:
       Node* prev;
       Node* next;
       int getInfo();
       void setInfo(int value);	
};

class DoublyLinkedList
{
 private:
     Node* head, *tail;    
     int size;
	
  public:
      DoublyLinkedList();   //initialize head and tail to 0 or NULL and size = 0;
     ~DoublyLinkedList();	
      void insertAtHead(int value);
      void insertAtTail(int value);
     void insertAtPos(int pos, int value);

    // Print the info value before deletion of the node
      void deleteAtHead();   
      void deleteAtTail();
      void deleteAtPos(int pos);
      void search(int value); //searches for a particular value in the list. Prints the location if found.
      void displayList();
};
*/
//Lab 03 - Doubly Linked List

//Header File:
#ifndef LAB_3_DLLIST_H
#define LAB_3_DLLIST_H

class Node {
    
public:
    int info;
    Node *prev;
    Node *next;
    int getinfo();
    void setInfo(int value);
};

class DoublyLinkedList {
    Node *head, *tail;
public:
    int size;
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertAtHead(int value);
    void insertAtTail(int value);
    void insertAtPos(int pos, int value);

    void deleteAtHead();
    void deleteAtTail();
    void deleteAtPos(int pos);

    void search(int value);
    void displayList();
};

#endif 

//Source File:
#include <iostream>
#include "DLList.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList(){ //created a constructor for initializing values
    this -> head = 0;
    this -> tail = 0;
    size = 0;
}

DoublyLinkedList::~DoublyLinkedList() { //created a destructor to free up memory and space
    Node *temp = head;
    while (temp != NULL) {
        Node * pointer = temp->next;
        delete temp;
        temp = pointer;
    }
    delete head;
    delete tail;
}

void DoublyLinkedList::insertAtHead(int value){ //created an insert function at the head of the list

    if (head == NULL){  //if head does not point to anything, list is empty
        head = new Node();
        head -> info = value;
        tail = head;
    }
    else{
        Node* temp = new Node(); //else assign new node to front of list
        temp -> info = value;
        temp -> next = head;
        head = temp;
    }
    size++; // count the number of elements in the list
}

void DoublyLinkedList::insertAtTail(int value) { //created an insert function at the tail of the list


    if (head == NULL) { //if head does not point to anything, list is empty
        head = new Node();
        head->info = value;
        tail = head;
    }
    else{
        Node* temp = new Node();    //else assign new node to the tail of list
        temp -> info = value;
        tail -> next = temp;
        tail = temp;
    }
    size++; // count the number of elements in the list
}

void DoublyLinkedList::insertAtPos(int pos, int value){
    if(pos < 1 || pos > size){	// if user tries to add a node in a non-existing index, print out of bounds
        cout << value << " cannot be added since the index " << pos << " is out of Bounds." << endl;
    }
    else{
        Node *prev = new Node;
        Node *current = new Node;
        Node *temp = new Node;
        current = head;
        
        for(int i = 1; i < pos; i++ ){
            prev = current;
            current = current -> next;
        }
        temp -> info = value;
        prev -> next = temp;
        temp -> next = current;
        cout << temp -> info << " was added at the position: " << pos << endl;
        size++;
    }
}

void DoublyLinkedList::deleteAtHead(){ //created a delete function to delete from the head of the list
    if (head == NULL){ //if head does not point to anything, list is empty
        cout << "The list is empty." << endl;
    }

    Node* deletedNode = head;

    head = head -> next;

    if (head == NULL){  //else delete the head and assign the second element as the head
        tail = NULL;
    }
    cout << "The info value that is being deleted is: " << deletedNode -> info << endl;
    size--;
}

void DoublyLinkedList::deleteAtTail() { //created a delete function to delete from the tail of the list
    if (head == NULL) { //if head does not point to anything, list is empty
        cout << "The list is empty." << endl;
    }

    if (head->next == NULL) {   //else delete the tail and assign the second last element as the tail
        cout << "The info value that is being deleted is: " << head->info << endl;
        head = NULL;
        tail = NULL;
    }

    Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    cout << "The info value that is being deleted is: " << temp->next->info << endl;
    temp->next = NULL;
    size--;
    
}

void DoublyLinkedList::deleteAtPos(int pos){ 
    if(pos < 1 || pos > size){ // if user tries to delete a node from a non-existing index, print out of bounds
        cout << "The index " << pos << " is out of Bounds." << endl;
    }
    
    else{
        Node *current = new Node;
        Node *prev = new Node;
        current = head;
    
        for (int i = 1 ; i < pos; i++){
            prev = current;
            current = current -> next;
        }
        cout << current -> info << " has been deleted at the position: " << pos << endl;
        prev -> next = current -> next;
        size--;
    }
}

void DoublyLinkedList::search(int value){ //search for a number from the list
    bool found = false;
    Node *temp = head;
    while(temp != NULL){
        if (temp -> info == value){
            found = true;
            break;
        }
        temp = temp -> next;
    }
    cout << "Searching for " << value << endl;
    if(found == true) {
        cout << "Number found." << endl;
    }
    else{
        cout << "Number not found." << endl;
    }
}

void DoublyLinkedList::displayList(){ //display the list
    Node*temp = head;
    if(temp == NULL){
        cout << "List is empty" << endl;
    }
    while(temp != NULL){
        cout << temp -> info << " ";
        temp = temp -> next;
    }
    cout << endl;
    cout << "Size of the list: " << size;
    cout << endl;
}
 
//Tester File:

#include "DLList.h"
#include <iostream>

using namespace std;

int main(){
    DoublyLinkedList A;

    A.insertAtHead(100);
    A.displayList();
    A.insertAtHead(55);
    A.displayList();
    A.insertAtHead(67);
    A.displayList();
    A.insertAtHead(359);
    A.displayList();
    A.insertAtPos(2,256);
    A.displayList();
    A.insertAtPos(15,214);
    A.displayList();
    


    A.insertAtTail(78);
    A.displayList();
    A.insertAtTail(89);
    A.displayList();
    A.insertAtTail(80);
    A.displayList();
    A.insertAtTail(45);
    A.displayList();

    A.deleteAtHead();
    A.displayList();
    A.deleteAtHead();
    A.displayList();
    A.deleteAtTail();
    A.displayList();
    A.deleteAtTail();
    A.displayList();
    A.deleteAtPos(2);
    A.displayList();
    A.deleteAtPos(65);
    A.displayList();

    A.search(5);
    A.displayList();
    A.search(93);
    A.displayList();
    A.search(78);
    A.displayList();

}


