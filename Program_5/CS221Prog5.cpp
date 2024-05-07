/*
CS221Prog5.cpp - Test Driver for Program 5.
Intended for Program 5 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#include "Sort.h"
#include "Sort1.h"
#include "Sort2.h"
#include "Sort3.h"

#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void SortItOut(Sort& sorter, int array[], int len);
void PrintArray(int array[], int len);
void PopulateArray(int array[], int len);
bool IsInArray(int array[], int len, int item);
void TimedSorted(Sort& sorter, int array[], int len);

int main() 
{
    srand(time(NULL)); // randomise the seed

    Sort1 bubbleSort;
    Sort2 mergeSort;
    Sort3 cocktailSort;

    const int ARRAY_SIZE = 100;

    int* array = new int[ARRAY_SIZE]; 

    // doing regular sorts

    PopulateArray(array, ARRAY_SIZE); // generates the array
    PrintArray(array, ARRAY_SIZE);
    SortItOut(bubbleSort, array, ARRAY_SIZE);

    PopulateArray(array, ARRAY_SIZE);
    SortItOut(mergeSort, array, ARRAY_SIZE);

    PopulateArray(array, ARRAY_SIZE);
    SortItOut(cocktailSort, array, ARRAY_SIZE);

    // timing sorts
    PopulateArray(array, ARRAY_SIZE);
    TimedSorted(bubbleSort, array, ARRAY_SIZE);

    PopulateArray(array, ARRAY_SIZE);
    TimedSorted(mergeSort, array, ARRAY_SIZE);

    PopulateArray(array, ARRAY_SIZE);
    TimedSorted(cocktailSort, array, ARRAY_SIZE);


    delete[] array;
    array = nullptr;
}

void SortItOut(Sort& sorter, int array[], int len)
{
    sorter.SetShowWork(true);
    sorter.Sorted(array, len);
    sorter.Print(array, len);
}

void TimedSorted(Sort& sorter, int array[], int len)
{
    sorter.SetShowWork(false);

    high_resolution_clock::time_point start = high_resolution_clock::now();
    sorter.Sorted(array, len);
    high_resolution_clock::time_point end = high_resolution_clock::now();

    sorter.Print(array, len);

    if (len < 100)
    {
        nanoseconds duration = duration_cast<nanoseconds>(end - start);
        cout << "Duration: " << duration.count() << "ns\n";
    }
    else
    {
        microseconds duration = duration_cast<microseconds>(end - start);
        cout << "Duration: " << duration.count() << "μs\n";
    }
}

void PrintArray(int array[], int len)
{
    cout << "Starting array: ";
    for (int index = 0; index < len; index++)   
    {
        cout << array[index] << " ";
    }
    cout << '\n';
}

void PopulateArray(int array[], int len)
{
    static int* copyArray = new int[len];
    if (copyArray[0] == 0)
    {
        // array has not been randomised yet, made a new array
        for (int index = 0; index < len; index++)
        {
            int newItem = rand() % (len * 10) + 1; // generate random item from 1 to 10 times the array size

            array[index] = newItem;
            copyArray[index] = newItem;
        }
    }
    else
    {
        // array has been randomised, need to just copy it over so that we can sort on the same array
        for (int index = 0; index < len; index++)
        {
            array[index] = copyArray[index];
        }
    }
}

bool IsInArray(int array[], int len, int item)
{
    bool found = false;

    for (int index = 0; index < len; index++)
    {
        if (array[index] == item)
        {
            found = true;
            break;
        }
    }
    return found;
}