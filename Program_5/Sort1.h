/*
Sort1.h - Declaration of the Sort1 class.
Intended for Program 5 in CS 221-03, Spring 2024 with Mrs. Delugach

Author: Jamie Roberson - This is my own work.
Email: jjr0028@uah.edu
Using compiler g++, Apple clang version 15.0.0
*/

#pragma once

#include "Sort.h"
#include <iostream>

using namespace std;

class Sort1 : public Sort
{
    public:
        Sort1();
        ~Sort1();

        void Sorted(int array[], int len) override;
        void Print(int array[], int len) override;
};