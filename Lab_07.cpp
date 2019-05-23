/*
CS 2413
 LAB – 7
Binary Search Tree


Q1. a) Use the BST from Lab 6 and a function to delete a specific node. The value to be deleted should be given by the user as an argument to the delete function. Display an error message if the value to be deleted is not found in the tree. Do not use structures.

b) Additionally, add methods for PreOrder and PostOrder tree traversal. You may use Stack Standard template library (STL) if needed (https://www.geeksforgeeks.org/stack-in-cpp-stl/ ). 

  										  [TOTAL: 15 points]
*/

//Main.cpp
#include <iostream>
#include "BST Lab 07.h"

using namespace std;

int main() {
    BST A;
    A.menu();
    return 0;
}
 
//BST Lab 07.h

#ifndef BST_LAB_07_H
#define BST_LAB_07_H

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
    Node* get_parent();
    void set_parent(Node *parent);

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
    void preorder();
    void preorderHelper(Node*);
    void postorder();
    void postorderHelper(Node*);
    
    int leavesCount();
    int CountHelper(Node*);
    void remove(int num);
};

#endif  //BST_LAB_06_H 

//BST Lab 07.cpp
#include "BST Lab 07.h"
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

Node* Node::get_parent(){
    return this->parent;
}

void Node::set_parent(Node *parent){
    this ->parent = parent;
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
    cout << "(5) Traverse the list pre order" << endl;
    cout << "(6) Traverse the list post order" << endl;
    cout << "(7) Delete a node" << endl;
    cout << "(8) Quit program" << endl;

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
            case 5: {// calls the traverse function
                cout << "Traversing the list..." << endl;
                preorder();
                break;
            }
            case 6: {// calls the traverse function
                cout << "Traversing the list..." << endl;
                postorder();
                break;
            }
            case 7: {
                cout << "Which node number do you want to delete?" << endl;
                cin >> val;
                cout << "Deleting node number " << val << "..." << endl;
                remove(val);
            }
            case 8:{ //exits the program
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

void BST::inorder(){ //traverses the BST in order
    this->inorderHelper(this->root);
}

void BST::inorderHelper(Node* node){ //recurcise function call
    if(node){
        this->inorderHelper(node->get_left());
        cout << node->getInfo() << " ";
        this->inorderHelper(node->get_right());
    }
}

void BST::preorder(){ //traverses the BST into pre order
    this->preorderHelper(this->root);
}

void BST::preorderHelper(Node* node){ //recurcise function call
    if(node){
        cout << node->getInfo() << " ";
        this->preorderHelper(node->get_left());
        this->preorderHelper(node->get_right());
    }
}

void BST::postorder(){ //traverses the BST into post order
    this->postorderHelper(this->root);
}

void BST::postorderHelper(Node* node){ //recurcise function call
    if(node){
        this->postorderHelper(node->get_left());
        this->postorderHelper(node->get_right());
        cout << node->getInfo() << " ";
    }
}

int BST::leavesCount(){ //counts number of nodes
    int count = 0;

    if(this->root){
        count = CountHelper(this->root);
    }
    return count;
}

int BST::CountHelper(Node* node){ //recursive function call
    int count = 1;

    if (node->get_left()){
        count+=CountHelper(node->get_left());
    }
    else if (node->get_right()){
        count+=CountHelper(node->get_right());
    }
    return count;
}

Node* BST::remove(int num){ //deletes a node
    Node *remNode = this->root;
    

    if ((remNode->getInfo()) != num) {
        cout << "Node does not exist";
    }
    else if (!(remNode -> get_right() || remNode ->get_left())){
        if (remNode->get_parent()){
            if (num < remNode -> get_parent() -> getInfo()){
                remNode -> get_parent() -> set_left(0);
            }
            else{
                remNode -> get_parent() -> set_right(0);
            }
        }
        else{
            this-> root = 0;
        }
        delete remNode;
    }
    else if(remNode-> get_right() && remNode-> get_left()){
        Node *temp = remNode -> get_right();
        //for (;temp -> get_left();temp = temp->get_left());
        while (temp -> get_left()){
            temp = temp -> get_left();
        }
        remNode -> setInfo(temp-> getInfo());
        if(num > temp -> get_parent() -> getInfo()){
            temp->get_parent()->set_right(temp->get_right());
            temp->get_right()->set_parent(temp->get_parent());
        }
        else{
            temp->get_parent()->set_left(temp->get_right());
            temp->get_right()->set_parent(temp->get_parent());
        }
    }
    else{
        if (remNode->get_left()){
            if(num < remNode -> get_parent() -> getInfo()){
                remNode-> get_parent()-> set_left(remNode-> get_left());
            }
            else{
                remNode ->get_parent()-> set_right(remNode->get_left());
            }
        }
        else {
            if (num < remNode->get_parent()->getInfo()) {
                remNode->get_parent()->set_left(remNode->get_right());
            }
            else {
                remNode->get_parent()->set_right(remNode->get_right());
            }
            remNode ->get_right()->set_parent(remNode->get_parent());
        }
        delete remNode;
    }
}
