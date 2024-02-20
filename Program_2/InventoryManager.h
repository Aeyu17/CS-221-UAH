/*
InventoryManager.h - Declaration of the InventoryManager class.
Intended for Program 2 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#pragma once

#include "Node.h"
#include "ItemType.h"

using namespace std;

class InventoryManager
{
    Node* head;
    Node* curPos;
    int maxLength;

    ItemType* GetItemNoPrint(ItemType* item, bool &found);

    public:
        InventoryManager();
        InventoryManager(int maxItems);
        ~InventoryManager();

        bool PutItem(ItemType* item);
        ItemType* GetItem(ItemType* item, bool &found);
        bool DeleteItem(ItemType* item);
        void ResetList();
        bool IsFull();
        void MakeEmpty();
        void PrintList();
        Node* GetNext();
        int GetLength();

};