/*
CityList.cpp - Definition of the CityList class.
Intended for Program 3 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#include "CityList.h"

// CONSTRUCTORS AND DESTRUCTORS

CityList::CityList()
{
    maxCapacity = DEFAULT_CAPACITY;
    length = 0;
    list = new ItemType[maxCapacity];
    curPos = 0;
}

CityList::CityList(int capacity)
{
    maxCapacity = capacity;
    length = 0;
    list = new ItemType[maxCapacity];
    curPos = 0;
    cout << "Jamie Roberson: Program 3\n";
}

CityList::CityList(const CityList &copyList)
{
    maxCapacity = copyList.maxCapacity;
    length = copyList.length;
    list = new ItemType[maxCapacity];
    curPos = copyList.curPos;
    for (int index = 0; index < length; index++)
    {
        list[index] = copyList.list[index];
    }
}

CityList::~CityList()
{
    MakeEmpty();

    delete[] list;
    list = nullptr;
}

// HELPER FUNCTIONS

bool CityList::PutItem(ItemType item)
{
    bool put = false;

    if (!IsFull())
    {
        for (int index = 0; index < maxCapacity; index++)
        {
            int date = 0;
            if (list[index] == item) // item is in list
            {
                item.PrintInfo();
                cout << " is already in the list!\n";
                break;
            }
            else if (list[index] > item)
            {
                put = true;
                for (int jindex = length - 1; jindex >= index; jindex--)
                {
                    list[jindex + 1] = list[jindex];
                }
                list[index] = item;
                break;
            }
            else if (index >= length && list[index].GetData(date) == "Nowhere" && date == 19700101)
            {
                put = true;
                list[index] = item;
                break;
            }
        }
    }
    else
    {
        cout << "The list is full!\n";
    }

    if (put)
    {
        cout << "Added ";
        item.PrintInfo();
        cout << '\n';
        length++;
    }

    return put;
}

ItemType CityList::GetItem(ItemType item, bool &found)
{
    found = false;
    cout << "Searching...\n";
    return CityList::GetItemRecursive(item, found, 0, length);
}

ItemType CityList::GetItemRecursive(ItemType item, bool &found, int start, int end)
{
    int middle = (start + end) / 2;
    list[middle].PrintInfo();
    cout << '\n';
    if (start == end && !(list[start] == item))
    {
        ItemType returnedItem;
        cout << "Not found.\n";
        return returnedItem;
    }
    else if (list[middle] == item)
    {
        found = true;
        cout << "Found!\n";
        return list[middle];
    }
    else if (list[middle] > item)
    {
        return CityList::GetItemRecursive(item, found, start, middle-1);
    }
    else if (list[middle] < item)
    {
        return CityList::GetItemRecursive(item, found, middle+1, end); 
    }
}

bool CityList::DeleteItem(ItemType item)
{
    bool deleted = false;
    for (int index = 0; index < length; index++)
    {
        if (list[index] == item) // item is in list
        {
            deleted = true;
            for (int jindex = index; jindex < length - 1; jindex++)
            {
                list[jindex] = list[jindex + 1];
            }
            break;
        }
        else if (list[index] > item)
        {
            break;
        }
    }

    if (deleted)
    {
        int date = 0; // unused variable
        cout << "Deleted " << item.GetData(date) << '\n';
        length--;
    }

    return deleted;
}

void CityList::ResetList()
{
    curPos = 0;
}

void CityList::MakeEmpty()
{
    delete[] list;

    list = new ItemType[maxCapacity];
    length = 0;
}

void CityList::PrintList()
{
    if (length == 0)
    {
        cout << "Nothing to print.\n";
    }
    else
    {
        cout << "PrintList:\n";
        for (int index = 0; index < length; index++)
        {
            list[index].PrintInfo();
            cout << " at index " << index << '\n';
        }
    }
    cout << '\n';
}

ItemType CityList::GetNext()
{
    ItemType item;
    if (curPos == length)
    {
        item = ItemType();
    }
    else
    {
        item = list[curPos];
        curPos++;
    }

    return item;
}

int CityList::GetLength()
{
    return length;
}

bool CityList::IsFull()
{
    return length == maxCapacity;
}