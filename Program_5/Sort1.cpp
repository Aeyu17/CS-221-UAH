/*
Sort1.cpp - Definition of the Sort1 class.
Intended for Program 5 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#include "Sort1.h"

Sort1::Sort1()
{
    cout << "Bubble Sort by Jamie Roberson\nMade in CS 221-03 for Program 5.\n";
    SetShowWork(false);
}

Sort1::~Sort1()
{
    // no cleanup necessary
}

// bubble sort
// this sort iterates through the array and checks if the next element is less than the current one, and if so it swaps them.
// it does this until the array is sorted.
// because the last element is guaranteed to be in the right place, we can remove it from our check for a small optimisation.
void Sort1::Sorted(int array[], int len)
{
    bool swapped = true; // flag that tells when we go through the full array without swapping

    int iterations = 0;

    while (swapped) // stay in loop if we did swap
    {
        swapped = false;
        for (int index = 0; index < len - iterations; index++)
        {
            if (array[index] > array[index + 1])
            {
                int temporary = array[index]; // swap the element and the next one
                array[index] = array[index + 1];
                array[index + 1] = temporary;
                swapped = true;
            }
        }

        iterations++;

        if (GetShowWork()) 
        {
            cout << iterations << ": ";
            for (int index = 0; index < len; index++)   
            {
                cout << array[index] << " ";
            }
            cout << '\n';
        }

    }
}

void Sort1::Print(int array[], int len)
{
    cout << "Bubble sort: ";
    for (int index = 0; index < len; index++)   
    {
        cout << array[index] << " ";
    }
    cout << '\n';
}