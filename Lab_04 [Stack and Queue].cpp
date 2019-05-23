/*
CS 2413
 LAB – 4
Stacks and Queues


1.	Turn your linked list from lab 2 into a Stack. At a minimum your Stack should have the functions listed below. Be sure to have a Stack.h, Stack.cpp and main.cpp file in your submission. This time write your program so that it asks the user for input. When pop is called the number that is popped should be displayed. Display a menu that asks the user their choice for the function that they want to execute:			           [10 pts]

•	push(int num)
•	pop
•	isEmpty
•	print
•	peek


2.	Turn your linked list from lab 2 into a Queue. At a minimum your Queue should have the functions listed below. Be sure to have a Queue.h, Queue.cpp and main.cpp file in your submission. This time write your program so that it asks the user for input. When Dequeue is called the number that is deleted should be displayed. Display a menu that asks the user their choice for the function that they want to execute:			           [10 pts]

•	enqueue(int num)
•	dequeue
•	isEmpty
•	print
•	peek

*/

//Stack.h
#ifndef STACK_H
#define STACK_H

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

class Stack {
public:
    Node *head, *tail;

    Stack();
    ~Stack();
    
    void destr_helper(Node *);
    void push(int num);
    int pop();
    void isEmpty();
    int peek();
    void menu();
    void displayList();
};

#endif
 

//Stack.cpp

#include "Stack.h"
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

Stack::Stack(){ //created a constructor for initializing values
    this -> head = 0;
    this -> tail = 0;
}

Stack::~Stack() { //created a destructor to free up memory and space
    destr_helper(this->head);
}

void Stack::destr_helper(Node *node){ 
    if(node){
        destr_helper(node->get_next());
        delete node;
    }
}

void Stack::push(int num){ //pushes user inputted integer to the head of the list
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

int Stack::pop(){ //pops the first element in the stack and sets the head to the new node/element
    if (!this->head){
        cout << "Stack is empty";
    }
    
    Node *temp = this -> head;
    this->head = temp -> get_next();
    
    
    if (this->head){
        this -> head -> set_prev(0);
    }
    else{
        this-> tail = 0;
    }
    
    int Info = temp -> get_info();
    cout << "The number that was popped off the stack was " << Info << endl;
    delete temp;
}

void Stack::isEmpty(){ //checks if the list is empty or not
    if (this->head == NULL) {
		cout << "True" << endl;
	}
	else{
	    cout << "False" << endl;
	}
}
int Stack::peek(){ //peeks at the element ready to be popped off but does not delete that element
    if (this->head) {
        return this-> head-> get_info();
    }
    else{
        throw "The Stack is empty";
    }
}

void Stack::menu(){ //menu for user input
	int userInput;
	int val;
	bool red = false;


	cout << "--------MENU--------" << endl;
	cout << "(1) Display list" << endl;
	cout << "(2) Push Value at head" << endl;
	cout << "(3) Pop Value from head" << endl;
	cout << "(4) Peek for a value" << endl;
	cout << "(5) Check if list is empty" << endl;
	cout << "(6) Quit program" << endl;
	
	while (red != true) { //input checker
		cout << "\nPlease enter a value from the menu: " << endl;
		cin >> userInput;
		switch (userInput) {
		case 1: //displays list
			cout << "Displaying the list..." << endl;
			displayList();
			break;
			
		case 2: //calls push function
			cout << "Pushing value at head" << endl;
			cout << "Enter the value to be inserted at the head: " << endl;
			cin >> val;
			while (!val) {
				cout << "Not a valid type, please try again." << endl;
				cin.clear();
				cin.get();
				cin >> val;
			}
			push(val);
			cout << "Value " << val << " pushed at head" << endl;
			break;
			
		case 3: //calls pop function
			cout << "Popping value" << endl;
			pop();
			break;

		case 4: //calls peek function
			cout << "Peek at the head of the list." << endl;
			cout << peek();
			cout << " is at the head of the list" << endl;
			break;

		case 5: //calls isEmpty function
		    cout << "Checking if the list is Empty..." << endl;
            cout << "[True - List is empty | False - List is not empty]" << endl;
            cout << "Result: " << endl;
            isEmpty();
            break;
            
        case 6: //exits the program
            red = true;
			break;
			
		default: //input checker
			cout << "Not a valid value, please try again" << endl;
			break;
		}
	}
}

void Stack::displayList(){ //display the list
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
 
//main.cpp

#include "Stack.h"
#include <iostream>

using namespace std;

int main(){
    Stack A;
    
    A.menu();
    return 0;
}
 
Output: 
  
