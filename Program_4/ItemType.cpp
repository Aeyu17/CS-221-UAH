/*
ItemType.cpp - Definition of the ItemType class.
Intended for Program 4 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#include "ItemType.h"

// CONSTRUCTORS AND DESTRUCTORS

ItemType::ItemType()
{
    name = "Jenny";
    address = "nowhere";
    phoneNumber = "2568675309";
}

ItemType::ItemType(string newName, string newAddress, string newPhoneNumber)
{
    name = newName;
    address = newAddress;
    phoneNumber = newPhoneNumber;
}

ItemType::~ItemType()
{
    // does nothing except destroying the Item
}

// OPERATOR OVERLOADS

bool ItemType::operator<(const ItemType &other)
{
    return name < other.name;
}

bool ItemType::operator>(const ItemType &other)
{
    return name > other.name;
}

bool ItemType::operator==(const ItemType &other)
{
    return name == other.name;
}

// GETTERS AND SETTERS

string ItemType::GetData()
{
    return name;
}

string ItemType::GetData(string &returnedAddress, string &returnedPhoneNumber)
{
    returnedAddress = address;
    returnedPhoneNumber = phoneNumber;
    return name;
}

void ItemType::SetData(string newName, string newAddress, string newPhoneNumber)
{
    name = newName;
    address = newAddress;
    phoneNumber = newPhoneNumber;
}

// HELPER FUNCTIONS

void ItemType::PrintInfo()
{
    cout << name << "," << address << "," << phoneNumber;
}