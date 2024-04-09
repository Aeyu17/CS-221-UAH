/*
ItemType.h - Declaration of the ItemType class.
Intended for Program 4 in CS 221-03, Spring 2024 with Mrs. Delugach

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
    private:
        string name;
        string address;
        string phoneNumber;

    public:
        ItemType();
        ItemType(string newName, string newAddress, string newPhoneNumber);
        ~ItemType();

        bool operator<(const ItemType &other);
        bool operator>(const ItemType &other);
        bool operator==(const ItemType &other);

        string GetData();
        string GetData(string &returnedAddress, string &returnedPhoneNumber);
        void SetData(string newName, string newAddress, string newPhoneNumber);

        void PrintInfo();
};