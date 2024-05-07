/*
Sort3.cpp - Definition of the Sort3 class.
Intended for Program 5 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#include "Sort3.h"

Sort3::Sort3()
{
    cout << "Cocktail Sort by Jamie Roberson\nMade in CS 221-03 for Program 5.\n";
    SetShowWork(false);
}

Sort3::~Sort3()
{
    // no cleanup necessary
}

// cocktail sort
// gotten from https://www.geeksforgeeks.org/cocktail-sort/
// this sort acts very similarly to bubble sort but instead of iterating through the array from front to back each time,
// it goes back and forth through the array. this has the effect of being able to manage small numbers at the end of an array
// much better than bubble sort. however, the methodology and time complexity remains largely the same.
void Sort3::Sorted(int array[], int len)
{
    bool swapped = true;
    int iterations = 0;

    while (swapped) // stay in the loop if we did swap
    {
        swapped = false;
        for (int index = 0; index < len - 2; index++)
        {
            if (array[index] > array[index + 1]) // swap elements so that greater elements go on the right
            {
                int temporary = array[index];
                array[index] = array[index + 1];
                array[index + 1] = temporary;
                swapped = true;
            }
        }

        if (!swapped) // if we didn't swap during an iteration we can just break; small optimisation
        {
            break;
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

        swapped = false;
        for (int index = len - 1; index >= 0; index--) // 
        {
            if (array[index] > array[index + 1])
            {
                int temporary = array[index];
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

void Sort3::Print(int array[], int len)
{    
    cout << "Cocktail sort: ";
    for (int index = 0; index < len; index++)   
    {
        cout << array[index] << " ";
    }
    cout << '\n';

}