/*
CS 2413
 LAB – 5
Linked List, Stacks and Queues


Q1. a) Add a function void deleteSmallest() to the linked list that you created in lab 2 that  finds and deletes the node with the smallest info in the list. Print the number before deletion. (Delete only the first occurrence and traverse the list only once.			        [5 points]

b) Add another function void removeDuplicates(int number)that finds and deletes all occurrences of the number from the list. Display an error message if the number is not in the list. (Traverse the list only once)							      [10 points]			      									      

Q2. Add a function void moveNthFront(int n) to the Queue that you created in lab 4 that takes as a parameter a positive integer, n. The function moves the nth element of the queue to the front of the Queue. The order of the remaining elements remains unchanged. 
For example, 
suppose queue = {5, 11, 34, 67, 43, 55} and n = 3. After a call to the function moveNthFront, queue = {34, 5, 11, 67, 43, 55}.
										                    [5 points]
*/
//Lab 05 (Question 1 (a) and (b))

//Lab 05.h
#ifndef LAB_05_H
#define LAB_05_H

class Node {

public:
    Node(int);
    Node();
    int info;
    Node *next;

};

class LinkedList {
public:
    Node *head, *tail;
    int size;

    LinkedList();
    ~LinkedList();

    void insertAtHead(int value);
    void insertAtTail(int value);

    void deleteAtHead();
    void deleteAtTail();

    void deleteSmallest();
    void removeDuplicates(int number);

    Node* get(int i);
    int rem(int i);
    void search(int value);
    void displayList();
};

#endif //LAB_05_H
 
//Lab 05.cpp
#include "Lab 05.h"
#include <iostream>
using namespace std;

Node::Node(int info){
    this-> info = info;
}

Node::Node(){
    this-> next = 0;
}

LinkedList::LinkedList(){ //created a constructor for initializing values
    this -> head = 0;
    this -> tail = 0;
    size = 0;
}

LinkedList::~LinkedList() { //created a destructor to free up memory and space
    Node *temp = head;
    while (temp != NULL) {
        Node * pointer = temp->next;
        delete temp;
        temp = pointer;
    }
    delete head;
    delete tail;
}

void LinkedList::insertAtHead(int value){ //created an insert function at the head of the list

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
    size++;

}

void LinkedList::insertAtTail(int value) { //created an insert function at the tail of the list


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

    size++;
}

void LinkedList::deleteAtHead(){ //created a delete function to delete from the head of the list
    if (head == NULL){ //if head does not point to anything, list is empty
        cout << "The list is empty." << endl;
        tail = NULL;
    }
    else { //else delete the head and assign the second element as the head

        Node *deletedNode = head;
        head = head->next;

        cout << "The info value that is being deleted is: " << deletedNode->info << endl;

        delete deletedNode;

        size--;
    }
}

void LinkedList::deleteAtTail() { //created a delete function to delete from the tail of the list
    if (head == NULL) { //if head does not point to anything, list is empty
        cout << "The list is empty." << endl;
    }

    else if (head->next == NULL) {   //else delete the tail and assign the second last element as the tail
        cout << "The info value that is being deleted is: " << head->info << endl;
        head = NULL;
        tail = NULL;
        size--;
    }
    else {
        Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        cout << "The info value that is being deleted is: " << temp->next->info << endl;
        temp->next = NULL;
        size--;
    }
}

Node* LinkedList::get(int j) {
    Node* temp = this->head;
    for(int i = 1; i <= j; i++){
        temp = temp->next;
    }
    return temp;
}
int LinkedList::rem(int i) {
    Node* prev;
    Node* rem;
    if(i == 0){
        int remData = this ->head->info;
        deleteAtHead();
        return remData;
    } else {
        prev = get(i - 1);
        if (prev->next == this->tail){
            int remData = this->tail->info;
            deleteAtTail();
            return remData;
        }
        rem = prev->next;
        prev->next = rem->next;
    }
    int remData = rem->info;
    delete rem;
    return remData;
}

void LinkedList::deleteSmallest(){
    Node* temp = this->head;
    Node* smallest = this->head;
    int j = 0;
    int temp_j = 0;
    for(;temp->next; temp = temp->next){
        if (temp->info < smallest->info){
            smallest = temp;
            j = temp_j;
        }
        temp_j++;
    }
    cout << "Smallest number to be removed: " << smallest -> info << endl;
    this->rem(j);
}
void LinkedList::removeDuplicates(int number) { //removing all occurrences of the number argument
        Node* temp = this->head;
        Node* rem;
        bool list = false;
        while(temp->next) {
            if (temp->next->info == number){
                list = true;
                rem = temp->next;
                temp->next = rem->next;
                delete rem;
            } else {
                temp = temp->next;
            }
        }
        if (!list){
            cout << "Deleting all occurrence of the number " << number << "..." << endl;
            cout << "Error: The number " << number << " is not in the list" << endl;
        }
    }

void LinkedList::search(int value){ //search for a number from the list
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

void LinkedList::displayList() { //display the list
    Node *temp = head;
    if (temp == NULL) {
        cout << "List is empty" << endl;
    }
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }

    cout << endl;
}
 
//Lab 05 Tester.cpp
#include "Lab 05.h"
#include <iostream>

using namespace std;

int main(){
    LinkedList * A = new LinkedList();

    A->insertAtHead(100);
    A->displayList();
    A->insertAtHead(55);
    A->displayList();
    A->insertAtHead(67);
    A->displayList();
    A->insertAtHead(9);
    A->displayList();
    A->insertAtHead(9);
    A->displayList();
    A->insertAtHead(359);
    A->displayList();

    A->insertAtTail(78);
    A->displayList();
    A->insertAtTail(78);
    A->displayList();
    A->insertAtTail(78);
    A->displayList();
    A->insertAtTail(89);
    A->displayList();
    A->insertAtTail(80);
    A->displayList();
    A->insertAtTail(80);
    A->displayList();
    A->insertAtTail(45);
    A->displayList();

    A->deleteAtHead();
    A->displayList();
    A->deleteAtHead();
    A->displayList();
    A->deleteAtTail();
    A->displayList();
    A->deleteAtTail();
    A->displayList();

    A->search(5);
    A->displayList();
    A->search(93);
    A->displayList();
    A->search(78);
    A->displayList();

    A->deleteSmallest();
    A->displayList();

    A->removeDuplicates(9);
    A->displayList();
    A->removeDuplicates(78);
    A->displayList();
}

//Lab 05 (Question 2)

//Lab 05 [Queue].h
#ifndef QUEUE_H
#define QUEUE_H

class Node {
public:
    int info;
    Node *next, *prev;
    Node(int);

    int get_info();
    void set_info(int);
    Node *get_next();
    void set_next(Node*);
    Node *get_prev();
    void set_prev(Node*);
};

class Queue {
public:
    Node *head, *tail;

    Queue();
    ~Queue();

    void destr_helper(Node *);
    void enqueue(int num);
    int dequeue();
    void isEmpty();
    int peek();
    void menu();
    void displayList();

    void moveNthFront(int n);
};

#endif
 
//Lab 05 [Queue].cpp
#include "Lab 05 [Queue].h"
#include <iostream>
using namespace std;

Node::Node(int info){ //initializing pointers
    this-> info = info;
    this-> next = 0;
    this-> prev = 0;
}

int Node::get_info() { //returns the value pointed by pointer
    return this->info;
}

void Node::set_info(int info) { //sets the value pointed by the pointer
    this -> info = info;
}

Node *Node::get_next() { //points to next node
    return this -> next;
}

void Node::set_next(Node * next) { //sets next node pointer
    this -> next = next;
}

Node * Node::get_prev() { //points to previous node
    return this-> prev;
}

void Node::set_prev(Node *prev) { //sets previous node pointer
    this -> prev = prev;
}

Queue::Queue(){ //created a constructor for initializing values
    this -> head = 0;
    this -> tail = 0;
}

Queue::~Queue() { //created a destructor to free up memory and space
    destr_helper(this->head);
}

void Queue::destr_helper(Node *node){
    if(node){
        destr_helper(node->get_next());
        delete node;
    }
}

void Queue::enqueue(int num){ //enqueues user inputted integer to the head of the list
    Node *newNode = new Node(num);

    newNode->set_next(this->head);

    if(this->head){
        this->head->set_prev(newNode);
    }
    else{
        this->tail = newNode;
    }

    this->head = newNode;
}

int Queue::dequeue(){ //deletes the last element in the queue and sets the tail to the second last element
    if (!this->head){
        cout << "Queue is empty";
    }

    Node *temp = this -> tail;
    this->tail = temp -> get_prev();


    if (this->tail){
        this -> tail -> set_next(0);
    }
    else{
        this-> head = 0;
    }

    int Info = temp -> get_info();
    cout << "The number that was dequeued off the stack was " << Info << endl;
    delete temp;

}

void Queue::isEmpty(){ //checks if the list is empty or not
    if (this->head == NULL) {
      cout << "True" << endl;
   }
   else{
       cout << "False" << endl;
   }
}

int Queue::peek(){ //peeks at the element ready to be dequeued off but does not delete that element
    if(!this->head){
        throw "The Queue is empty";
    }
    if(this->tail) {
        return this-> tail-> get_info();
    }
}

void Queue::menu(){ //menu for user input
   int userInput;
   int val;
    int n;
   bool red = false;


   cout << "--------MENU--------" << endl;
   cout << "(1) Display list" << endl;
   cout << "(2) Enqueue Value at head" << endl;
   cout << "(3) Dequeue Value from tail" << endl;
   cout << "(4) Peek for a value" << endl;
   cout << "(5) Check if list is empty" << endl;
    cout << "(6) Move an element to the front of the list" << endl;
   cout << "(7) Quit program" << endl;

   while (red != true) { //input checker
      cout << "\nPlease enter a value from the menu: " << endl;
      cin >> userInput;
      switch (userInput) {
      case 1: //displays list
         cout << "Displaying the list..." << endl;
         displayList();
         break;

      case 2: //calls enqueue function
         cout << "Enqueuing value at head" << endl;
         cout << "Enter the value to be inserted at the head: " << endl;
         cin >> val;
         while (!val) {
            cout << "Not a valid type, please try again." << endl;
            cin.clear();
            cin.get();
            cin >> val;
         }
         enqueue(val);
         cout << "Value " << val << " enqueued at head" << endl;
         break;

      case 3: //calls dequeue function
         cout << "Dequeuing value" << endl;
         dequeue();
         break;

      case 4: //calls peek function
         cout << "Peek at the tail of the list." << endl;
         cout << peek();
         cout << " is at the tail of the list" << endl;
         break;

      case 5: //calls isEmpty function
          cout << "Checking if the list is Empty..." << endl;
            cout << "[True - List is empty | False - List is not empty]" << endl;
            cout << "Result: ";
            isEmpty();
            break;

        case 6: //calls moveNthFront function and moves the user inputted Nth index integer to the front of the list
            if(head==NULL){
                cout << "Sorry cannot do that since the list is empty." << endl;
                break;
            }
            cout << "Type the index number for the element that you would like to move to the front of the list: " ;
            cin >> n;
            while (!n) {
                cout << "Not a valid type, please try again." << endl;
                cin.clear();
                cin.get();
                cin >> n;
            }
            while (n < 0) {
                cout << "Index out of bounds, please try again." << endl;
                cin.clear();
                cin.get();
                cin >> n;
            }
            moveNthFront(n);
            break;

        case 7: //exits the program
            red = true;
         break;

      default: //input checker
         cout << "Not a valid value, please try again" << endl;
         break;
      }
   }
}

void Queue::displayList(){ //display the list
    Node*temp = head;

    if(temp == NULL){
        cout << "List is empty" << endl;
    }

    while(temp != NULL){
        cout << temp -> get_info() << " ";
        temp = temp -> get_next();
    }
    cout << endl;
}

void Queue::moveNthFront(int n){ // copies the ‘to-be’ deleted element, deletes it, and pastes it to the front of the list

    Node *remove = head;
    int i;
    Node *temp;

    for (i=0; i < n; i++){
        remove->prev = remove;
        remove = remove->next;
    }

    if (remove->prev == 0){
        remove->next->prev = 0;
        enqueue(remove->get_info());
        delete remove;
    }

    else if(remove->next == 0){
        remove->prev->next = 0;
        enqueue(remove->get_info());
        delete remove;
    }

    else{
        remove->prev->next = remove->next;
        remove->next->prev = remove->prev;
        enqueue(remove->get_info());
        delete remove;
    }
}

//Lab 05 [Queue] Tester.cpp
#include "Lab 05 [Queue].h"
#include <iostream>

using namespace std;

int main(){
    Queue *A = new Queue;

    A -> menu();
    return 0;
}

