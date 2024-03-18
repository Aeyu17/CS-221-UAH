/*
ItemType.cpp - Definition of the ItemType class.
Intended for Program 3 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#include "ItemType.h"

// CONSTRUCTORS AND DESTRUCTORS

ItemType::ItemType()
{
    date = 19700101;
    city = "Nowhere";
}

ItemType::ItemType(int newDate, string newCity)
{
    date = newDate;
    city = newCity;
}

ItemType::~ItemType()
{
    // all members are static, no need for destructor clean up
}

// OVERLOADED OPERATORS

bool ItemType::operator<(const ItemType &other)
{
    return city < other.city;
}

bool ItemType::operator>(const ItemType &other)
{
    return city > other.city;
}

bool ItemType::operator==(const ItemType &other)
{
    return city == other.city;
}

// GETTERS AND SETTERS

string ItemType::GetData()
{
    return city;
}

string ItemType::GetData(int &returnedDate)
{
    returnedDate = date;
    return city; 
}

void ItemType::SetData(int newDate, string newCity)
{
    date = newDate;
    city = newCity;
}

// HELPER FUNCTIONS

void ItemType::PrintInfo()
{
    cout << "On: " << date << ", to: " << city;
}