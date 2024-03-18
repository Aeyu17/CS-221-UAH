/*
CityList.h - Declaration of the CityList class.
Intended for Program 3 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#pragma once

#include <string>
#include "ItemType.h"

using namespace std;

class CityList
{
    const int DEFAULT_CAPACITY = 10;

    int maxCapacity;
    ItemType* list;
    int length;
    int curPos;

    ItemType GetItemRecursive(ItemType item, bool &found, int start, int end);
    
    public:
        CityList();
        CityList(int capacity);
        CityList(const CityList &copyList);
        ~CityList();

        bool PutItem(ItemType item);
        ItemType GetItem(ItemType item, bool &found);
        bool DeleteItem(ItemType item);
        void ResetList();
        void MakeEmpty();
        void PrintList();
        ItemType GetNext();
        int GetLength();
        bool IsFull();
};