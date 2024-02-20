/*
InventoryManager.cpp - Definition of the InventoryManager class.
Intended for Program 2 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#include "InventoryManager.h"
#include <iostream>

using namespace std;

// CONSTRUCTORS AND DESTRUCTORS

InventoryManager::InventoryManager()
{
    // remains empty
}

InventoryManager::InventoryManager(int maxItems)
{
    cout << "Welcome to Angkrit Car Lot Inventory, run by Jamie Roberson.\n";
    head = nullptr;
    curPos = nullptr;
    maxLength = maxItems;
}

InventoryManager::~InventoryManager()
{
    MakeEmpty();
}

// MEMBER FUNCTIONS

bool InventoryManager::PutItem(ItemType* item)
{
    bool found = false;

    if (item != nullptr && !IsFull())
    {
        GetItemNoPrint(item, found);

        if (!found)
        {
            Node* newNode = new Node(*item);

            newNode->SetNext(head);
            head = newNode;

            string description = "";
            long long int vin = item->GetData(description);
            cout << "Added: " << description << ", " << vin << " at " << newNode << "\n\n";
        }
        else
        {
            string data = ""; // unused variable
            cout << item->GetData(data) << ", " << data << " is already present.\n\n";
        }
    }

    return found;

}

ItemType* InventoryManager::GetItemNoPrint(ItemType* item, bool &found)
{
    // fix the cout statements
    found = false;
    Node* curPtr = head;

    while (item != nullptr && curPtr != nullptr)
    {
        ItemType curItem = curPtr->GetItem();
        if (curItem.Compare(item) == EQUAL)
        {
            found = true;
            break;
        }

        curPtr = curPtr->Next();
    }

    if (found)
    {
        return new ItemType(curPtr->GetItem());
    }
    else
    {
        return nullptr;
    }
    
}

ItemType* InventoryManager::GetItem(ItemType* item, bool &found)
{
    // fix the cout statements
    found = false;
    Node* curPtr = head;
    cout << "Searching...\n";

    while (item != nullptr && curPtr != nullptr)
    {
        ItemType curItem = curPtr->GetItem();
        string description = "";
        curItem.GetData(description);
        cout << description << "; ";

        if (curItem.Compare(item) == EQUAL)
        {
            cout << "Found.\n";
            found = true;
            break;
        }

        curPtr = curPtr->Next();
    }

    if (found)
    {
        return new ItemType(curPtr->GetItem());
    }
    else
    {
        return nullptr;
    }
    
}

bool InventoryManager::DeleteItem(ItemType* item)
{
    // finish
    bool found = false;
    Node* curPtr = head;
    Node* lastPtr = nullptr;

    if (item != nullptr)
    {
        if (head->GetItem().Compare(item) == EQUAL)
        {
            found = true;
            string description = "";
            long long int vin = curPtr->GetItem().GetData(description);
            cout << "Deleted: " << vin << ", " << description << " at " << curPtr << "\n\n";

            Node* newHead = curPtr->Next();

            delete curPtr;
            curPtr = nullptr;

            head = newHead;
        }
        else
        {
            lastPtr = curPtr;
            curPtr = curPtr->Next();
        }

        while (curPtr != nullptr)
        {
            if (curPtr->GetItem().Compare(item) == EQUAL)
            {
                found = true;
                string description = "";
                long long int vin = curPtr->GetItem().GetData(description);
                cout << "Deleted: " << vin << ", " << description << " at " << curPtr << "\n\n";

                lastPtr->SetNext(curPtr->Next());
                delete curPtr;
                curPtr = nullptr;

                break;
            }

            curPtr = curPtr->Next();
        }
    }

    return found;
}

void InventoryManager::ResetList()
{
    curPos = head;
}

bool InventoryManager::IsFull()
{
    return GetLength() == maxLength;
}

void InventoryManager::MakeEmpty()
{
    Node* curPtr = head;
    Node* delPtr = nullptr;

    while (curPtr != nullptr)
    {
        delPtr = curPtr;
        curPtr = curPtr->Next();

        delete delPtr;
        delPtr = nullptr;
    }

    head = nullptr;
    curPos = nullptr;
    cout << "The list has been emptied.\n";
}

void InventoryManager::PrintList()
{
    Node* curPtr = head;

    while (curPtr != nullptr)
    {
        string description = "";
        long long int vin = curPtr->GetItem().GetData(description);
        cout << description << ", " << vin << " at " << curPtr << "\n";
        
        curPtr = curPtr->Next();
    }
}

Node* InventoryManager::GetNext()
{
    Node* returnPtr = curPos;

    if (curPos != nullptr)
    {
        curPos = curPos->Next();
    }

    return returnPtr;
}

int InventoryManager::GetLength()
{
    int counter = 0;
    Node* curPtr = head;

    while (curPtr != nullptr)
    {
        curPtr = curPtr->Next();
        counter++;
    }

    return counter;
}