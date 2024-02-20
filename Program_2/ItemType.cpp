/*
ItemType.cpp - Definition of the ItemType class.
Intended for Program 2 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#include "ItemType.h"

#include <iostream>

using namespace std;

// CONSTRUCTORS AND DESTRUCTORS

ItemType::ItemType()
{
    description = DEFAULT_DESCRIPTION;
    vin = DEFAULT_VIN;
}

ItemType::ItemType(string newDescription, long long int newVin)
{
    description = newDescription;
    vin = newVin;
}

ItemType::~ItemType()
{
    // remains empty  
}

// GETTER

long long int ItemType::GetData(string &data)
{
    data = description;
    return vin;
}

// HELPER FUNCTIONS

Equality ItemType::Compare(ItemType* item)
{
    string data = ""; // unused variable

    if (vin > item->GetData(data)) 
    {
        return GREATER;
    } 
    else if (vin < item->GetData(data)) 
    {
        return LESS;
    }
    else
    {
        return EQUAL;
    }
}

void ItemType::PrintInfo()
{
    cout << vin << ", " << description << '\n';
}