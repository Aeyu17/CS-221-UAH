/*
Node.cpp - Definition of the Node class.
Intended for Program 2 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#include "Node.h"

#include <string>

using namespace std;

// CONSTRUCTORS AND DESTRUCTORS

Node::Node()
{
    // remains empty
}

Node::Node(ItemType newItem)
{
    item = new ItemType(newItem);
    next = nullptr;
}

Node::~Node()
{
    delete item;
    item = nullptr;
    next = nullptr;
}

// GETTERS

ItemType Node::GetItem()
{
    return *item;
}

Node* Node::Next()
{
    return next;
}

// SETTER

void Node::SetNext(Node* nextNode)
{
    if (nextNode != nullptr) 
    {
        next = nextNode;
    }
}