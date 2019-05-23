/*
CS 2413
 LAB – 6
Binary Search Tree


Q1. a) Write a C++ program to implement a Binary Search tree (do not use structures). Your program should accept a list of numbers from the user (minimum 5) and then build a binary search tree from those numbers. Also, implement a search function that takes one value as an argument and prints whether or not the number was found in the list. Define three files:  bst.h, bst.cpp and your main,cpp to test your code. Use the given code at the end to create the Binary Search Tree.

b) Write the definition of the function, leavesCount, that returns the number of leaves in a binary tree.

c) Print the contents of your tree using inorder traversal. You may use Stack STL if needed. 
  										  [TOTAL: 15 points]

class Node
{
   	int info;
 public:
     Node(int info); 
     int getInfo();
	void setInfo(int value);
	Node *left, *right;
};

class BST
{
	Node *root;
 public:
	BST();
	~BST();
     void insert(int);
	void/bool search(int);  //you can either make it void or bool
	void inorderTraversal();
	void/int leavesCount();
};
*/

//BST.h
#ifndef BST_LAB_06_H
#define BST_LAB_06_H

class Node
{
    int info;
    Node *left, *right, *parent;

public:
    Node(int);
    int getInfo();
    void setInfo(int value);

    Node *get_left();
    void set_left(Node *left);
    Node *get_right();
    void set_right(Node *right);

};

class BST
{
    Node *root;

public:
    BST();
    ~BST();
    void menu();
    void destr_helper(Node*);
    void insert(int);
    bool search(int);
    bool search_helper(Node *node, int num);
    void inorder();
    void inorderHelper(Node*);
    int leavesCount();
    int CountHelper(Node*);
};

#endif  //BST_LAB_06_H

//BST.cpp
#include "BST Lab 06.h"
#include <iostream>

using namespace std;

Node::Node(int info){
    this-> info = info;
    this-> left = NULL;
    this-> right = NULL;
    this-> parent = NULL;
}

int Node::getInfo(){
    return this -> info;
}

void Node::setInfo(int value){
    this -> info = value;
}

Node* Node::get_left() {
    return this-> left;
}

void Node::set_left(Node *left){
    this-> left = left;
}

Node *Node::get_right(){
    return this-> right;
}

void Node::set_right(Node *right) {
    this-> right = right;
}

void BST::menu(){ //menu for user input
    int userInput;
    int val = 0;
    bool red = false;
    int i;
    int a;

    cout << "--------MENU--------" << endl;
    cout << "(1) Add numbers to the list" << endl;
    cout << "(2) Search a value" << endl;
    cout << "(3) Count the number of leaves" << endl;
    cout << "(4) Traverse the list in order" << endl;
    cout << "(5) Quit program" << endl;

    while (red != true) {

        cout << "\nPlease enter a value from the menu: " << endl;
        cin >> userInput;

        switch (userInput) {

            case 1: {//calls insert function
                cout << "Adding numbers..." << endl;
                cout << "Enter 6 numbers: " << endl;

                for (i=1; i<7 ; i++) {
                    if(i==1){
                        cout << "Enter the " << i << "st value: ";
                        cin >> val;
                        insert(val);
                    }
                    else if(i==2){
                        cout << "Enter the " << i << "nd value: ";
                        cin >> val;
                        insert(val);
                    }
                    else if(i==3){
                        cout << "Enter the " << i << "rd value: ";
                        cin >> val;
                        insert(val);
                    }
                    else{
                        cout << "Enter the " << i << "th value: ";
                        cin >> val;
                        insert(val);
                    }
                }

                while (cin.fail()) {
                    cout << "Not a valid type, please try again." << endl;
                    cin.clear();
                    //cin.get();
                    cin >> val;
                }
                break;
            }
            case 2:{ // calls the search function
                cout << "Search a Value..." << endl;
                cout << "Note: [Number Found - True | Number Not Found - False]" << endl;
                cout << "Please enter a value to be found: ";
                cin >> a;
                bool isFound = search(a);
                cout << isFound << endl;

                while (!a) {
                    cout << "Not a valid type, please try again." << endl;
                    cin.clear();
                    //cin.get();
                    cin >> a;
                }
                break;
            }
            case 3:{ // calls the leavesCount function
                cout << "Counting the number of leaves..." << endl;
                cout << "The number of leaves in the BST is/are: " << leavesCount() << endl;
                break;
            }
            case 4: {// calls the traverse function
                cout << "Traversing the list..." << endl;
                inorder();
                break;
            }
            case 5:{ //exits the program
                red = true;
                break;
            }
            default:{ //input checker
                cout << "Not a valid value, please try again" << endl;
            }
        }
    }
}

BST::BST(){ // constructor
    this->root = 0;
}

BST::~BST(){ // destructor
    this-> destr_helper(this->root);

}
void BST::destr_helper(Node* node) {
    if (node != 0) {
        this->destr_helper(node->get_left());
        this->destr_helper(node->get_right());
        delete node;
    }
}
void BST::insert(int num){ //adds a new node
    Node *temp = this->root;
    Node *newNode = new Node(num);

    if(!(this->root)){
        this->root = newNode;
    }
    else{
        while(temp){
            if(newNode->getInfo() > temp->getInfo()){
                if(temp->get_right()){
                    temp = temp->get_right();
                }
                else{
                    temp->set_right(newNode);
                    break;
                }
            }
            else if(newNode->getInfo() < temp->getInfo()){
                if(temp->get_left()){
                    temp = temp->get_left();
                }
                else{
                    temp->set_left(newNode);
                    break;
                }
            }
            else{
                cout << "Duplicates not allowed";
                break;
            }
        }
    }
}

bool BST::search(int num){
    return this->search_helper(this->root, num);
}

bool BST::search_helper(Node *node, int num) {
    if (!node){
        return false;
    }
    else if (node -> getInfo() == num){
        return true;
    }
    else if (num < node -> getInfo()){
        return this-> search_helper(node->get_left(), num);
    }
    else{
        return this->search_helper(node-> get_right(),num);
    }
}


void BST::inorder(){
    this->inorderHelper(this->root);
}

void BST::inorderHelper(Node* node){
    if(node){
        this->inorderHelper(node->get_left());
        cout << node->getInfo() << " ";
        this->inorderHelper(node->get_right());
    }
}

int BST::leavesCount(){
    int count = 0;

    if(this->root){
        count = CountHelper(this->root);
    }
    return count;
}
int BST::CountHelper(Node* node){
    int count = 1;

    if (node->get_left()){
        count+=CountHelper(node->get_left());
    }
    else if (node->get_right()){
        count+=CountHelper(node->get_right());
    }
    return count;
}

//BST_main.cpp
#include <iostream>
#include "BST Lab 06.h"

using namespace std;

int main() {
    BST A;
    A.menu();
    return 0;
}
