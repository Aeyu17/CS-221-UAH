/*
Sort2.h - Declaration of the Sort2 class.
Intended for Program 5 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#pragma once

#include "Sort.h"
#include <iostream>

using namespace std;

class Sort2 : public Sort
{
    private:
        int iterations = 0;
        void mergeSort(int array[], int start, int end);
    public:
        Sort2();
        ~Sort2();

        void Sorted(int array[], int len) override;
        void Print(int array[], int len) override;
};