/*
ItemType.h - Declaration of the ItemType class.
Intended for Program 3 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#pragma once

#include <string>
#include <iostream>

using namespace std;

class ItemType 
{
    int date;
    string city;

    public:
        ItemType();
        ItemType(int newDate, string newCity);
        ~ItemType();

        bool operator<(const ItemType &other);
        bool operator>(const ItemType &other);
        bool operator==(const ItemType &other);

        string GetData();
        string GetData(int &returnedDate);
        void SetData(int newDate, string newCity);

        void PrintInfo();
};