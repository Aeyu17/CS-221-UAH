/*
Sort2.cpp - Definition of the Sort2 class.
Intended for Program 5 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#include "Sort2.h"

Sort2::Sort2()
{
    cout << "Merge Sort by Jamie Roberson\nMade in CS 221-03 for Program 5.\n";
    iterations = 0;
    SetShowWork(false);
}

Sort2::~Sort2()
{
    // no cleanup necessary
}

// merge sort
// this sort divides an array into two parts recursively until the arrays are of size one.
// then, the sort merges the sub-arrays back together by iterating through the arrays and adding the smallest element first
// the sort does this until the entire array is sorted in place.
void Sort2::Sorted(int array[], int len)
{
    mergeSort(array, 0, len-1);
}

void Sort2::mergeSort(int array[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);

        const int leftLength = mid - start + 1;
        const int rightLength = end - mid;
        int* leftArray = new int[leftLength]; // create two new arrays to split the specified area into
        int* rightArray = new int[rightLength];

        // copy the data into those arrays
        for (int index = 0; index < leftLength; index++)
        {
            leftArray[index] = array[start + index];
        }
        for (int index = 0; index < rightLength; index++)
        {
            rightArray[index] = array[mid + 1 + index];
        }

        int leftIndex = 0, rightIndex = 0;
        int arrayIndex = start;

        // the actual sorting part
        // add the left element if it's smaller, the right element else
        // increment the indices until you hit the end of one of the arrays
        while (leftIndex < leftLength && rightIndex < rightLength)
        {
            if (leftArray[leftIndex] < rightArray[rightIndex])
            {
                array[arrayIndex] = leftArray[leftIndex];
                leftIndex++;
            }
            else
            {
                array[arrayIndex] = rightArray[rightIndex];
                rightIndex++;
            }
            arrayIndex++;
        }

        // copy the rest of the elements into the main array
        while (leftIndex < leftLength)
        {
            array[arrayIndex] = leftArray[leftIndex];
            leftIndex++;
            arrayIndex++;
        }
        while (rightIndex < rightLength)
        {
            array[arrayIndex] = rightArray[rightIndex];
            rightIndex++;
            arrayIndex++;
        }

        iterations++;
        if (GetShowWork())
        {
            cout << iterations << ": ";
            for (int index = start; index <= end; index++)
            {
                cout << array[index] << " ";
            }
            cout << '\n';
        }
        
        // memory cleanup from using dynamic arrays
        delete[] leftArray;
        delete[] rightArray;
    }
}


void Sort2::Print(int array[], int len)
{
    cout << "Merge sort: ";
    for (int index = 0; index < len; index++)   
    {
        cout << array[index] << " ";
    }
    cout << '\n';
}