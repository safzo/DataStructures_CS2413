//Graph.h
// Created by Safwan Hasan on 11/2/18.
//

#ifndef GRAPH_H
#define GRAPH_H

class Node {
public:
    int label;
    Node *next;
    AdjNode * head;
    Node (int);
    bool visited;
};

class AdjNode{
public:
    Node *node;
    AdjNode *next;
    AdjNode(Node*);
};

class Graph{
    Node *head, *visited, *stackQueue, *queueTail;
    void destr_helper(Node *);
    void destr_helper2(AdjNode *);
    void push(Node*);
    Node *pop(bool);

public:
    Graph();
    ~Graph();
    void add_node(int);
    void add_edge(int, int);
    void rem_node(int);
    void rem_edge(int, int);
    void BFT(int);
    void DFT(int);
};
#endif //GRAPH_H

//Graph.cpp
#include "Graph.h"

Node::Node(int label){
    this-> label = label;
    this->next = 0;
    this->head = 0;
    this->visited = false;
}

AdjNode::AdjNode(Node *node){
    this->next = 0;
    this->node = node;
}

Graph::Graph(){
    this->head = 0;
    this->queueTail = 0;
    this->visited = 0;
    this->stackQueue = 0;
}

Graph::~Graph(){
    destr_helper(this->head);
}

void Graph::destr_helper(Node* node) {
    if(node){
        destr_helper(node->next);
        destr_helper2(node->head);
        delete node;
    }
}

void Graph::destr_helper2(AdjNode* node){
    if (node) {
        destr_helper2(node->next);
        delete node;
    }
}

void Graph::add_node(int label){
    Node *temp = this->head;
    while (temp){
        if (temp-> label == label){
            throw "duplicate node already exists";
        }
        else {
            temp = temp->next;
        }
    }

    Node *newNode = new Node (label);
    newNode -> next = this->head;
    this->head = newNode;
}
