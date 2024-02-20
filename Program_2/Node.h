/*
Node.h - Declaration of the Node class.
Intended for Program 2 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#pragma once

#include "ItemType.h"

class Node
{
    ItemType* item;
    Node* next;

    public:
        Node();
        Node(ItemType newItem);
        ~Node();

        ItemType GetItem();
        Node* Next();
        void SetNext(Node* nextNode);
};