/*
ItemType.h - Declaration of the ItemType class.
Intended for Program 2 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#pragma once

#include <string>

using namespace std;

enum Equality
{
    LESS = -1,
    EQUAL = 0,
    GREATER = 1
};

class ItemType
{
    const string DEFAULT_DESCRIPTION = "Undefined car";
    const long long int DEFAULT_VIN = 0;

    string description;
    long long int vin;

    public:
        ItemType();
        ItemType(string newDescription, long long int newVin);
        ~ItemType();

        Equality Compare(ItemType* item);
        long long int GetData(string &data);
        void PrintInfo();
};